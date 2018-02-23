//implement node using Vector

#include <usuffix.h>

struct UkkonenTree::Node {
    Vector<Edge> children;      //Sorted vector of child node pointers. Finding an edge O(log m)
                                                    //Inserting and edge: O(m)
                                                    //where m=size of alphabet
    UkkonenTree* tree;
    Node* suffixlink; //Suffix link pointer
    
    int id=0;
    //To iterate through
    void init_iteration(){
        id=0;
    }
    Edge current(){
        return children[id];
    }
    void next_iter(){
        ++id;
    }
    bool iteration_ended(){
        return id==(int)children.size();
    }
    
    int findChildIndex(int c){
        int a=0; int b=children.size()-1;
        if (b<0) return -1;
        while (a<=b){
            int v=children[a].firstCharacter;
            if (v==c || v==-1) return a;
            ++a;
        }
        return -1;
    }

    UkkonenTree::Edge findEdge(int i){
        return children[i];
    }


    void setSuffixlink(Node* to) {
        suffixlink=to;
    }
    
    Node* getSuffixlink(){
        return suffixlink;
    }

    void addEdge(Edge& edge, int index){
        tree->calcFirstCharacter(edge);
        if (index<0) children.push_back(edge);
        else children[index]=edge;
    }


    //constructor and destructor
    Node(UkkonenTree* tree_){suffixlink=0; tree=tree_;}
    ~Node(){}
};


#include "usuffix.cpp"