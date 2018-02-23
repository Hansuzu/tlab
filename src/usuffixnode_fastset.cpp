//Implement node using fastSet

#include <fastset.h>
#include <usuffix.h>

struct UkkonenTree::Node {
    FastSet<Edge> children;         //Set of children. Finding an edge O(log^2 m)
                                                    //Inserting and edge: O(log m)
                                                    //where m=size of alphabet
    
    UkkonenTree* tree;                                              
    Node* suffixlink; //Suffix link pointer
    
    

    int id;
    //To iterate through
    void init_iteration(){
        id=children.firstIndex();
    }
    Edge current(){
        return children.findByIndex(id);
    }
    void next_iter(){
        id=children.nextIndex(id);
    }
    bool iteration_ended(){
        return id<0;
    }
    
    int findChildIndex(int c){
        Edge f(NULL, 0, 0); f.firstCharacter=c;
        int ind=children.findIndex(f);
        if (ind>=0) return ind;
        f.firstCharacter=-1;
        return children.findIndex(f);
    }
    
    UkkonenTree::Edge findEdge(int i){
        return children.findByIndex(i);
    }
    
    void addEdge(Edge& edge, int index){
        tree->calcFirstCharacter(edge);
        if (index<0) children.insert(edge);
        else children.insertToIndex(index, edge);
    }
    
    void setSuffixlink(Node* to) {
        suffixlink=to;
    }
    Node* getSuffixlink(){
        return suffixlink;
    }
    
    Node(UkkonenTree* tree_){
        tree=tree_;
        Edge t(NULL, 0, 0);
        t.firstCharacter=(1ull<<31)-1; //Max integer value;
        children.set_max_element(t);
        suffixlink=0;
    }
    ~Node(){}
};


#include "usuffix.cpp"




