#include <bits/stdc++.h> //include everything from standard library (will be later replaced with something all removed...)
#ifndef USUFFIX_H
#define USUFFIX_H

#include <fastset.h>

//Ukkonen's paper: https://www.cs.helsinki.fi/u/ukkonen/SuffixT1withFigs.pdf



//Integers in range 0,1,...,sizeOfAlphabet-1 will be used as alphabet.




class UkkonenTree{

public: //everything public to make unit testing easy
    //

    std::vector<int> str; //The current string (represented as a vector of integers)
    
    struct Node;
    struct Edge{
        Node* targetNode; //Where edge leads to
        int l, r; //Left and right pointer to the substring in str which corresponds to this edge
        int firstCharacter; //Used often, this makes it faster.
        //r<0 means that r is inf (open transition)
        //l<0  means that edge is from aux to root and can be any character
        Edge(Node* targetNode_, int l_, int r_){targetNode=targetNode_; l=l_; r=r_;}
        Edge(){}
        void operator=(const Edge& o){
            targetNode=o.targetNode;
            l=o.l;
            r=o.r;
            firstCharacter=o.firstCharacter;
        }
        //FastSet uses this
        bool operator<(const Edge& o){
            return firstCharacter<o.firstCharacter;
        }
    };
    void calcFirstCharacter(Edge& e); // When edge created or edited, this shoudl be called. This updates firstCharacter.
    
    struct Node {
//         FastSet<Edge> children;  
        std::vector<Edge> children;      //Sorted vector of child node pointers. Finding an edge O(log m)
                                                       //Inserting and edge: O(m)
                                                       //where m=size of alphabet
        Node* suffixlink; //Suffix link pointer
        
        //constructor and destructor (defined in usuffix.cpp)
        Node(); 
        ~Node();
    };
    
    //Following functinos are used internally:
    int findChildIndex(Node* parent, int c); //Finds a edge of character c. Returns -lower_bound-1 (negative number) if edge does not exist.
    Edge findEdge(Node* parent, int i); //returns the edge with index i
    
    Node* addChild(Node* node, int l, int r, int index); //creates new child node for a node, returns a pointer to the newly created node
    void addEdge(Node* parent, Edge& edge, int index); //adds an edge from node to child 
    void setSuffixlink(Node* from, Node* to);
    
    
    
    struct Reference{ //Ukkonen, page 8
        //Refers to some state (corresponding some suffix of str) of suffix tree. (possibly state is in the middle of an edge, "implicit state")
        //"add substring of str from l to r to substring corresponding node s"
        //Reference is canonical, if node s is lowest possible
    private:
        Node* s; //node
        int l, r; // pointers to string
        
        int childIndex;//Save child index so it doesn't have to be calculated so may times...
                        //Speeds up almost 5% :Dd
                        
        void resetChildIndex(){childIndex=-99;}
    public:
        int getChildIndex(){ return childIndex;}
        int setChildIndex(int id){return childIndex=id;}
        
        int getL(){ return l;}
        int getR(){ return r;}
        Node* getS(){ return s;}
        void setL(int l_){ l=l_;  resetChildIndex();}
        void setR(int r_){ r=r_;}
        void setS(Node* s_){ s=s_;  resetChildIndex();}
        
        Reference(Node* ss, int ll, int rr):s(ss),l(ll),r(rr){
            resetChildIndex();
        }
        Reference(){
            resetChildIndex();
        }
        
    };
    
    int childIndex(Reference& ref){
        int id=ref.getChildIndex();
        if (id==-99) return ref.setChildIndex(findChildIndex(ref.getS(), str[ref.getL()]));
        return id;
    }
    
    
    //Ukkonen, pages 11,12,13
    void update(Reference& ref); // follows boundary route from ref (canonical) to end-point
                                     // calls canonize and testAndSplit
                                     // 
    std::pair<bool, Node*> testAndSplit(Reference& ref, int chr); //Takes a canonical reference and character which is being appended to str
                                                                 //Makes referenced state explicit by splitting an edge it if needed.
                                                                 //Returns new state and <0 if it is not an end-point (chr-transition did not exist)
                                                                 //Returned value is a index where chr-transition can be inserted
                                                                 //Returns 0 and new state if is an end-point (chr-transition existed)
    void canonize(Reference& ref); // Make a reference canonical (Make the node pointed by reference lowest possible)
    
    
    Node root;
    Node aux; // The auxiliary state (Ukkonen, page 3)
    
    Reference activePoint; //Ukkonen, page 9
    
    
public:    
    void push(int chr); // append a single character to the tree
    void push(std::vector<int>& astr, int delta=0); // append a  string represented as std::vector<int> to the tree (adds delta to each integer)
    void push(std::string& astr, int delta=0);  //append a string represented as std::string to the tree
    
    
    Reference getChild(Reference ref, int c); // If there exist a state ref+c, return canonized reference to it. If fail, returned Reference.s=NULL
    
    bool isSubstring(std::vector<int>& astr, int delta=0);
    bool isSubstring(std::string& astr, int delta=0);
    
    UkkonenTree(){
        Edge e(&root, -1, -1);
        addEdge(&aux, e, -1);
        setSuffixlink(&root, &aux); //Suffix link from root to auxiliary state
        activePoint=Reference(&root, 0, -1); //initial active state is root
    }
    
    
    
    std::map<Node*, std::string> dnames;
    std::string dotFormatDFS(Node* node, std::map<Node*, std::string>& names, int delta=0); // getDotFormat calls this, handles the subtree of node
    std::string getDotFormat(int delta=0); // Returns tree represented in the format used by command line tool dot (which can be used to draw it)
};


#endif