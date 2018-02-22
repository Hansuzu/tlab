//usuffix.cpp file in include folder, because template-class-stuff.

#include <bits/stdc++.h>
#include <usuffix.h>

struct UkkonenTree::Node {
    Vector<Edge> children;      //Sorted vector of child node pointers. Finding an edge O(log m)
                                                    //Inserting and edge: O(m)
                                                    //where m=size of alphabet
    Node* suffixlink; //Suffix link pointer
    
    //constructor and destructor
    Node(){suffixlink=0;}
    ~Node(){}
};




int UkkonenTree::findChildIndex(Node* parent, int c){
    int a=0; int b=parent->children.size()-1;
    if (b<0) return -1;

    while (a<b){
        int m=(a+b)/2;
        if (parent->children[m].firstCharacter<c) a=m+1;
        else b=m;
    }
    int v=parent->children[a].firstCharacter;
    if (v==c || v==-1){
        return a;
    }
    if (v<c) return -(a+1)-1;
    return -a-1;
}

UkkonenTree::Edge UkkonenTree::findEdge(Node* parent, int i){
    return parent->children[i];
}


void UkkonenTree::calcFirstCharacter(Edge& e){
    e.firstCharacter=(e.l >= 0 ? str[e.l] : -1);
}


void UkkonenTree::addEdge(Node* parent, Edge& edge, int index){
    calcFirstCharacter(edge);
    int id=findChildIndex(parent, edge.firstCharacter); 
    if (id<0){ //Child doesn't exist yet.
        id=-(id+1); //This will be the index of this child
        parent->children.emplace_back(edge);
        for (int i=parent->children.size()-1; i>id; --i){ // Move all the elements with i>id
            parent->children[i]=parent->children[i-1];
        }
    }
    parent->children[id]=edge;
}





UkkonenTree::Node* UkkonenTree::addChild(Node* node, int l, int r, int index){
    //Create new node
    Node* to=new Node; 
    //add it as a child of the parent node
    Edge e(to, l, r);
    addEdge(node, e, index);
    //return the new node
    return to;
}


void UkkonenTree::setSuffixlink(Node* from, Node* to) {
    from->suffixlink=to;
}




//Ukkonen, page 12
void UkkonenTree::update(Reference& ref) {
    //follow boundary route from ref to end point
    int i=ref.getR()+1; //reference is to the state before the new character, i is the index of the new character
    Node* oldr=NULL;
    std::pair<bool, Node*> endr=testAndSplit(ref, str[i]);
    while (!endr.first){ //While not an end point of the boundary route

        //this state is not an end-point => new leaf needs to bee added
        addChild(endr.second, i, -1, -1); //add new state node
        
        //add suffix link from previous node (if there is one) to this new new node
        if (oldr) setSuffixlink(oldr, endr.second); 
        oldr=endr.second;
        //follow the suffixlink of the current node in reference and canonize
        ref.setS(ref.getS()->suffixlink);
        
        canonize(ref);
        
        endr=testAndSplit(ref, str[i]);
    }
    if (oldr) setSuffixlink(oldr, ref.getS());
}

//Ukkonen, page 12

std::pair<bool, UkkonenTree::Node*> UkkonenTree::testAndSplit(Reference& ref, int chr) {
    if (ref.getL()<=ref.getR()){ //referenced state not explicit
        int child_index=childIndex(ref);
        int i=findEdge(ref.getS(), child_index).l + (ref.getR()-ref.getL());//i=index corresponding to ref.r in edges l-r range 
                                                             //(edges l is not necessarily same as ref.l)
        if (str[i+1]==chr){ //transition already exists, state is an end-state => return true
            return std::make_pair(true, ref.getS());
        }else{ //transition does not exist, splitting needed
            Edge pEdge=findEdge(ref.getS(), child_index); //Get original edge
            Node* newNode=addChild(ref.getS(), ref.getL(), ref.getR(), child_index);  //Add new node, replaces the original edge
            pEdge.l+=(ref.getR()-ref.getL()+1); //fix left boundary of original edge (must be done before addEdge)
            calcFirstCharacter(pEdge);
            addEdge(newNode, pEdge, -1); //Add original edge to newly created node
            return std::make_pair(false, newNode);
        }
    }else{ //referenced state explicit, no splitting needed
        if (childIndex(ref)<0){ //transition does not exist, return false
            return std::make_pair(false, ref.getS());
        }else{ //transition exists, return true
            return std::make_pair(true, ref.getS());
        }
    }
}

//Ukkonen page 13

void UkkonenTree::canonize(Reference& ref){
    if (ref.getL()<=ref.getR()){ //Only non-explicit references may need canonization
        Edge edge=findEdge(ref.getS(), childIndex(ref)); //Get correct transition from ref.s
        while (edge.l<0  || (edge.r - edge.l <= ref.getR() - ref.getL()  && edge.r!=-1)) { //While not canonized = while edge from ref.s is too short
                                                                                     //if edge is from aux (edge->l<0) it can be proved to always be too short (but comparison would not work)
             // go to next node and update ref.l
            ref.setS(edge.targetNode);
            if (edge.l<0)  ref.setL(ref.getL()+1); //edge is from aux
            else           ref.setL(ref.getL()+edge.r - edge.l +1);
            
            if (ref.getR()<ref.getL()) break; //reference to explicit node   
            edge=findEdge(ref.getS(), childIndex(ref));
        }
    }
}







void UkkonenTree::push(int chr){
    str.push_back(chr);
    update(activePoint);
    activePoint.setR(activePoint.getR()+1); //new active point
    canonize(activePoint);
}

void UkkonenTree::push(std::vector<int>& astr, int delta){
    for (int i=0; i<(int)astr.size(); ++i){
        push(astr[i]+delta);
    }
}

void UkkonenTree::push(std::string& astr, int delta){
    std::vector<int> data(astr.begin(), astr.end());
    push(data, delta);
}





UkkonenTree::Reference UkkonenTree::getChild(Reference ref, int c){
    // If there exist a state ref+c, return canonized reference to it. If fail, returned Reference.s=NULL
    if (ref.getL()<=ref.getR()){
        int i=findEdge(ref.getS(), findChildIndex(ref.getS(), str[ref.getL()])).l + (ref.getR()-ref.getL());//i=index corresponding to ref.r in edges l-r range 
        if (str[i+1]!=c){ 
            ref.setS(NULL);
            return ref;
        }else{
            ref.setR(ref.getR()+1);
            canonize(ref);
            return ref;
        }
    }else{
        int id=findChildIndex(ref.getS(), c);
        if (id>=0){
            int b=findEdge(ref.getS(), id).l;
            ref.setL(b); ref.setR(b);
            canonize(ref);
            return ref;
        }else{
            ref.setS(NULL);
            return ref;
        }
    }
}



bool UkkonenTree::isSubstring(std::vector<int>& astr, int delta){
    Reference state(root, 1, 0);
    for (int i=0; i<(int)astr.size(); ++i){
        state=getChild(state, astr[i]+delta);
        if (state.getS()==NULL) return 0;
    }
    return 1;
}


bool UkkonenTree::isSubstring(std::string& astr, int delta){
    std::vector<int> data(astr.begin(), astr.end());
    return isSubstring(data, delta);
}






//For drawing

std::string UkkonenTree::dotFormatDFS(Node* node, std::map<Node*, std::string>& names, int delta){
    if (!names.count(node)) names[node]=std::to_string(names.size()-2);
    std::string ans="";/*
    for (int i=0; i<(int)node->children.size(); ++i) {
        Node* target=node->children[i].targetNode;
        int l=node->children[i].l;
        int r=node->children[i].r;
        std::string label="";
        for (int j=l; j<=(r==-1?(int)str.size()-1:r); ++j) label.push_back(str[j]+delta);
        if (r==-1)label+="...";
        ans+=dotFormatDFS(target, names, delta);
        ans+="\t"+names[node]+" -> "+names[target]+" [label=\""+label+"\"];\n";
    }
    if (!names.count(node->suffixlink)) names[node->suffixlink]=std::to_string(names.size()-2);
    if (node->suffixlink){
        ans+="\t"+names[node]+" -> "+names[node->suffixlink]+" [style=dashed arrowhead=halfopen];\n";
    }*/
    return ans;
}



std::string UkkonenTree::getDotFormat(int delta){
    std::string result="digraph{\n\taux;\n\troot=aux;\n";
    dnames[aux]="aux";
    dnames[root]="root";
    result+=dotFormatDFS(root, dnames, delta);

    result+="\t"+dnames[activePoint.getS()]+" [label=\""+dnames[activePoint.getS()]+"* ("+std::to_string(activePoint.getL())+", "+std::to_string(activePoint.getR())+")\"];\n";
    result+="\t"+dnames[aux]+" -> "+dnames[root]+";\n}";
    return result;
}




UkkonenTree::UkkonenTree(){
    root=new Node();
    aux=new Node();
    Edge e(root, -1, -1);
    addEdge(aux, e, -1);
    setSuffixlink(root, aux); //Suffix link from root to auxiliary state
    activePoint=Reference(root, 0, -1); //initial active state is root
}