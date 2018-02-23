//Implement node using Vector

#include <usuffix.h>

struct UkkonenTree::Node {
    Vector<Edge> children;      //Sorted vector of child node pointers. Finding an edge O(log m)
                                                    //Inserting and edge: O(m)
                                                    //where m=size of alphabet
    UkkonenTree* tree;
    Node* suffixlink; //Suffix link pointer
    
    int id;
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

        while (a<b){
            int m=(a+b)/2;
            if (children[m].firstCharacter<c) a=m+1;
            else b=m;
        }
        int v=children[a].firstCharacter;
        if (v==c || v==-1){
            return a;
        }
        if (v<c) return -(a+1)-1;
        return -a-1;
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
        int ind=findChildIndex(edge.firstCharacter); 
        if (ind<0){ //Child doesn't exist yet.
            ind=-(ind+1); //This will be the index of this child
            children.emplace_back(edge);
            for (int i=children.size()-1; i>ind; --i){ // Move all the elements with i>id
                children[i]=children[i-1];
            }
        }
        children[ind]=edge;
    }
    //constructor and destructor
    Node(UkkonenTree* tree_){suffixlink=0; tree=tree_;}
    ~Node(){}
};

#include "usuffix.cpp"

