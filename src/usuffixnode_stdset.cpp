//Implement node using std::set

#include <set> // std::set
#include <usuffix.h>

struct UkkonenTree::Node {
    std::set<Edge> children;         //Set of children. Finding an edge O(log m)
                                                    //Inserting and edge: O(log m)
                                                    //where m=size of alphabet
    UkkonenTree* tree;
    Node* suffixlink; //Suffix link pointer
    
    std::set<Edge>::iterator it; // Hack to make function next() work.
    
    //To iterate through
    void init_iteration(){
        it=children.begin();
    }
    Edge current(){
        return *it;
    }
    void next_iter(){
        ++it;
    }
    bool iteration_ended(){
        return it==children.end();
    }
    
    
    int findChildIndex(int c){
        Edge f(NULL, 0, 0); f.firstCharacter=c;
        if (children.count(f)) return c+1;
        f.firstCharacter=-1;
        if (children.count(f)) return c+1;
        return -1;
    }

    UkkonenTree::Edge findEdge(int i){
        Edge f(NULL, 0, 0); f.firstCharacter=i-1;
        
        auto t=children.find(f);
        if (t!=children.end()) return *t;
        f.firstCharacter=-1;
        t=children.find(f);
        if (t!=children.end()) return *t;
        return f; //Lol, not found. should never happen
    }

    

    void setSuffixlink(Node* to) {
        suffixlink=to;
    }
    
    Node* getSuffixlink(){
        return suffixlink;
    }
    
    void addEdge(Edge& edge, int index){
        tree->calcFirstCharacter(edge);
        if (index>=0) children.erase(edge);
        children.insert(edge);
    }


    Node(UkkonenTree* tree_){suffixlink=0; tree=tree_;}
    ~Node(){}
};


#include "usuffix.cpp"