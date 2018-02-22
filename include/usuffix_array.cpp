//OLD IMPLEMENTATION

//usuffix.cpp file in include folder, because template-class-stuff.

#include <bits/stdc++.h> //include everything from standard library (will be later replaced with something all removed...)


//Node constructor
template<int sizeOfAlphabet>
UkkonenTree<sizeOfAlphabet>::Node::Node(){
    memset(children, 0, sizeOfAlphabet*sizeof(Node*));
    suffixlink=0;
}
//Node destructor
template<int sizeOfAlphabet>
UkkonenTree<sizeOfAlphabet>::Node::~Node(){
    
}





template<int sizeOfAlphabet>
void UkkonenTree<sizeOfAlphabet>::addEdge(Node* parent, Edge* edge){
    //add edge to the parent
    //if l<0, the index character is r, otherwise str[l]
    parent->children[edge->l < 0  ?  edge->r : str[edge->l]]=edge;
}

template<int sizeOfAlphabet>
void UkkonenTree<sizeOfAlphabet>::addAsChild(Node* parent, Node* child, int l, int r){
    //Create an edge to the child node
    Edge* e=new Edge;
    e->targetNode=child;
    e->l=l;
    e->r=r;
    addEdge(parent, e);
}


template<int sizeOfAlphabet>
typename UkkonenTree<sizeOfAlphabet>::Node* UkkonenTree<sizeOfAlphabet>::addChild(Node* node, int l, int r){
    //Create new node
    Node* to=new Node; 
    //add it as a child of the parent node
    addAsChild(node, to, l, r);
    //return the new node
    return to;
}

template<int sizeOfAlphabet>
void UkkonenTree<sizeOfAlphabet>::setSuffixlink(Node* from, Node* to) {
    from->suffixlink=to;
}




//Ukkonen, page 12
template<int sizeOfAlphabet>
typename UkkonenTree<sizeOfAlphabet>::Reference UkkonenTree<sizeOfAlphabet>::update(Reference ref) {
    //follow boundary route from ref to end point
    int i=ref.r+1; //reference is to the state before the new character, i is the index of the new character
    Node* oldr=NULL;
    std::pair<bool, Node*> endr=testAndSplit(ref, str[i]);
    while (!endr.first){ //While not an end point of the boundary route

        //this state is not an end-point => new leaf needs to bee added
        addChild(endr.second, i, -1); //add new state node
        
        //add suffix link from previous node (if there is one) to this new new node
        if (oldr) setSuffixlink(oldr, endr.second); 
        oldr=endr.second;
        //follow the suffixlink of the current node in reference and canonize
        ref.s=ref.s->suffixlink;
        ref=canonize(ref);
        
        endr=testAndSplit(ref, str[i]);
    }
    if (oldr) setSuffixlink(oldr, ref.s);
    return ref; // return end-point, it will be used to calculate new active point (Ukkonen, page 13)
}

//Ukkonen, page 12
template<int sizeOfAlphabet>
std::pair<bool, typename UkkonenTree<sizeOfAlphabet>::Node*> UkkonenTree<sizeOfAlphabet>::testAndSplit(Reference ref, int chr) {
    if (ref.l<=ref.r){ //referenced state not explicit
        int i=ref.s->children[str[ref.l]]->l + (ref.r-ref.l);//i=index corresponding to ref.r in edges l-r range 
                                                             //(edges l is not necessarily same as ref.l)
        if (str[i+1]==chr){ //transition already exists, state is an end-state => return true
            return std::make_pair(true, ref.s);
        }else{ //transition does not exist, splitting needed
            Edge* pEdge=ref.s->children[str[ref.l]]; //Get pointer of original edge
            Node* newNode=addChild(ref.s, ref.l, ref.r);  //Add new node, replaces the original edge
            pEdge->l+=(ref.r-ref.l+1); //fix left boundary of original edge (must be done before addEdge)
            addEdge(newNode, pEdge); //Add original edge to newly created node
            return std::make_pair(false, newNode);
        }
    }else{ //referenced state explicit, no splitting needed
        if (ref.s->children[chr]==NULL){ //transition does not exist, return false
            return std::make_pair(false, ref.s);
        }else{ //transition exists, return true
            return std::make_pair(true, ref.s);
        }
    }
}

//Ukkonen page 13
template<int sizeOfAlphabet>
typename UkkonenTree<sizeOfAlphabet>::Reference UkkonenTree<sizeOfAlphabet>::canonize(Reference ref){
    if (ref.r<ref.l){ //Explicit, already canonized
        return ref;
    }else{
        Edge* edge=ref.s->children[str[ref.l]]; //Get correct transition from ref.s
        while (edge->l<0  || (edge->r - edge->l <= ref.r - ref.l  && edge->r!=-1)) { //While not canonized = while edge from ref.s is too short
                                                                                     //if edge is from aux (edge->l<0) it can be proved to always be too short (but comparison would not work)
             // go to next node and update ref.l
            ref.s=edge->targetNode;
            if (edge->l<0) ref.l+=1; //edge is from aux
            else           ref.l+=edge->r - edge->l +1; 
            if (ref.r<ref.l) break; //reference to explicit node
            edge=ref.s->children[str[ref.l]];
        }
        return ref;
    }
}






template<int sizeOfAlphabet>
void UkkonenTree<sizeOfAlphabet>::push(int chr){
    str.push_back(chr);
    activePoint=update(activePoint);
    activePoint.r+=1; //new active point
    activePoint=canonize(activePoint);
    
}
template<int sizeOfAlphabet>
void UkkonenTree<sizeOfAlphabet>::push(std::vector<int>& astr, int delta){
    for (int i=0; i<(int)astr.size(); ++i){
        push(astr[i]+delta);
    }
}

template<int sizeOfAlphabet>
void UkkonenTree<sizeOfAlphabet>::push(std::string& astr, int delta){
    std::vector<int> data(astr.begin(), astr.end());
    push(data, delta);
}



template<int sizeOfAlphabet>
typename UkkonenTree<sizeOfAlphabet>::Reference UkkonenTree<sizeOfAlphabet>::getChild(Reference ref, int c){
    // If there exist a state ref+c, return canonized reference to it. If fail, returned Reference.s=NULL
    if (ref.l<=ref.r){
        int i=ref.s->children[str[ref.l]]->l + (ref.r-ref.l);//i=index corresponding to ref.r in edges l-r range 
        if (str[i+1]!=c){ ref.s=NULL;
            return ref;
        }else{
            ref.r+=1;
            return canonize(ref);
        }
    }else{
        if (ref.s->children[c]){
            ref.l=ref.r=ref.s->children[c]->l;
            return canonize(ref);
        }else{ ref.s=NULL;
            return ref;
        }
    }
}


template<int sizeOfAlphabet>
bool UkkonenTree<sizeOfAlphabet>::isSubstring(std::vector<int>& astr, int delta){
    Reference state(&root, 1, 0);
    for (int i=0; i<(int)astr.size(); ++i){
        state=getChild(state, astr[i]+delta);
        if (state.s==NULL) return 0;
    }
    return 1;
}

template<int sizeOfAlphabet>
bool UkkonenTree<sizeOfAlphabet>::isSubstring(std::string& astr, int delta){
    std::vector<int> data(astr.begin(), astr.end());
    return isSubstring(data, delta);
}






//For drawing
template<int sizeOfAlphabet>
std::string UkkonenTree<sizeOfAlphabet>::dotFormatDFS(Node* node, std::map<Node*, std::string>& names, int delta){
    if (!names.count(node)) names[node]=std::to_string(names.size()-2);
    std::string ans="";
    for (int i=0; i<sizeOfAlphabet; ++i) {
        if (node->children[i]){
            Node* target=node->children[i]->targetNode;
            int l=node->children[i]->l;
            int r=node->children[i]->r;
            std::string label="";
            for (int j=l; j<=(r==-1?(int)str.size()-1:r); ++j) label.push_back(str[j]+delta);
            if (r==-1)label+="...";
            ans+=dotFormatDFS(target, names, delta);
            ans+="\t"+names[node]+" -> "+names[target]+" [label=\""+label+"\"];\n";
        }
    }
    if (!names.count(node->suffixlink)) names[node->suffixlink]=std::to_string(names.size()-2);
    if (node->suffixlink){
        ans+="\t"+names[node]+" -> "+names[node->suffixlink]+" [style=dashed arrowhead=halfopen];\n";
    }
    return ans;
}


template<int sizeOfAlphabet>
std::string UkkonenTree<sizeOfAlphabet>::getDotFormat(int delta){
    std::string result="digraph{\n\taux;\n\troot=aux;\n";
    dnames[&aux]="aux";
    dnames[&root]="root";
    result+=dotFormatDFS(&root, dnames, delta);

    result+="\t"+dnames[activePoint.s]+" [label=\""+dnames[activePoint.s]+"* ("+std::to_string(activePoint.l)+", "+std::to_string(activePoint.r)+")\"];\n";
    result+="\t"+dnames[&aux]+" -> "+dnames[&root]+";\n}";
    return result;
}


