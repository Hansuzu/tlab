#include <bits/stdc++.h> //include everything from standard library (will be later replaced with something all removed...)
#include <usuffix.h> 


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
    parent->children[edge->l<0?edge->r:str[edge->l]]=edge;
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
void UkkonenTree<sizeOfAlphabet>::setSuffixlink(Node* from, Node* to){
    from->suffixlink=to;
}




//Ukkonen, page 12
template<int sizeOfAlphabet>
typename UkkonenTree<sizeOfAlphabet>::Reference UkkonenTree<sizeOfAlphabet>::update(Reference ref){
    //follow boundary route from ref
    int i=ref.second;
    ref.r=i-1;
    Node* oldr=NULL;
    std::pair<bool, Node*> endr=testAndSplit(ref, str[i]);
    while (!endr.first){ //While not an end point of the boundary route
        addChild(endr.second, i, -1); //add new node
        //add suffix link from previously created new node (if any) to this new new node
        if (oldr) setSuffixlink(oldr, endr.second); 
        oldr=endr.second;
        //follow the suffixlink of the current node in reference and canonize
        ref=canonize(Reference(ref.s->suffixlink, ref.l, ref.r));
        
        endr=testAndSplit(ref, str[i]);
    }
    if (oldr)   setSuffixlink(oldr, ref.s);
    return ref;
}

//Ukkonen, page 12
template<int sizeOfAlphabet>
std::pair<bool, typename UkkonenTree<sizeOfAlphabet>::Node*> UkkonenTree<sizeOfAlphabet>::testAndSplit(Reference ref, int chr){
    if (ref.r<=ref.r){ //referenced state not explicit
        if (str[ref.r+1]==chr){ //route exists.
            return std::make_pair(true, ref);
        }else{ //route does not exist, splitting needed
            Edge* pEdge=ref.s->children[ref.l];
            Node* newNode=addChild(ref.s, ref.l, ref.r);
            addEdge(newNode, pEdge);
            pEdge->l=ref.r+1;
            ref.s=newNode;
            //TODO TODO TODO TODO
            //TODO TODO TODO TODO
            return std::make_pair(false, ref);
        }
    }else{ //referenced state explicit, no splitting needed
        if (ref.s->children[chr]==NULL){ //route does not exists
            return std::make_pair(false, ref);
        }else{//route exists
            return std::make_pair(true, ref);
        }
    }
}

//Ukkonen page 13
template<int sizeOfAlphabet>
typename UkkonenTree<sizeOfAlphabet>::Reference UkkonenTree<sizeOfAlphabet>::canonize(Reference ref){
    
}






template<int sizeOfAlphabet>
void UkkonenTree<sizeOfAlphabet>::push(int chr){
    str.push_back(chr);
}
template<int sizeOfAlphabet>
void UkkonenTree<sizeOfAlphabet>::push(std::vector<int>& str){
    for (int i=0; i<str.size(); ++i){
        push(str[i]);
    }
}

template<int sizeOfAlphabet>
void UkkonenTree<sizeOfAlphabet>::push(std::string str){
    
    std::vector<int> data(str.begin(), str.end());
    push(data);
}



