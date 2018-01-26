#include <bits/stdc++.h> //include everything from standard library (will be later replaced with something all removed...)



//Ukkonen's paper: https://www.cs.helsinki.fi/u/ukkonen/SuffixT1withFigs.pdf



//Integers in range 0,1,...,sizeOfAlphabet-1 will be used as alphabet.

template<int sizeOfAlphabet> class UkkonenTree{

public: //everything public to make unit testing easy
    
    std::vector<int> str; //The current string (represented as a vector of integers)
    
    struct Node;
    struct Edge{
        Node* targetNode; //Where edge leads to
        int l, r; //Left and right pointer to the substring in str which corresponds to this edge
        //r<0 means that r is inf (open transition)
        //l<0  means that edge is from aux to root for character r
    };
    struct Node {
        Edge* children[sizeOfAlphabet]; //Array of child node pointers, finding an edge with a certain first character works in O(1)
                                        //Node space complexity is O(m) thus the space complexity altogether will be O(n*m)
                                        //m=size of alphabet, n=size of string
        Node* suffixlink; //Suffix link pointer
        
        //constructor and destructor (defined in usuffix.cpp)
        Node(); 
        ~Node();
    };
    
    
    Node* addChild(Node* node, int l, int r); //creates new child node for a node, returns a pointer to the newly created node
    void addEdge(Node* parent, Edge* edge); //adds an edge from node to child
    void addAsChild(Node* parent, Node* child, int l, int r); //adds an edge from node to child
    void setSuffixlink(Node* from, Node* to);
    
    
    struct Reference{ //Ukkonen, page 8
        Node* s;
        int l, r;
        Reference(Node* ss, int ll, int rr):s(ss),l(ll),r(rr){}
        Reference(){}
    };
    
    //Ukkonen, pages 11,12,13
    Reference update(Reference ref);
    std::pair<bool, Node*> testAndSplit(Reference ref, int chr);
    Reference canonize(Reference ref);
    
    
    Node root;
    Node aux; // The auxiliary state (Ukkonen, page 3)
    
    Reference activePoint; //Ukkonen, page 9
    
    
public:
    
    void push(int chr); // append a single character to the tree
    void push(std::vector<int>& str); // append a  string represented as std::vector<int> to the tree
    void push(std::string str);  //append a string represented as std::string to the tree
    
    UkkonenTree(){
        for (int i=0; i<sizeOfAlphabet; ++i){ // Add routes for all characters from auxiliary state to the root.
            addAsChild(&aux, &root, -1, i);
        }
    }
};