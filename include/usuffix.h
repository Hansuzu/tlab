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
                                        //where m=size of alphabet, n=size of string
        Node* suffixlink; //Suffix link pointer
        
        //constructor and destructor (defined in usuffix.cpp)
        Node(); 
        ~Node();
    };
    
    //Following functinos are used internally:
    Node* addChild(Node* node, int l, int r); //creates new child node for a node, returns a pointer to the newly created node
    void addEdge(Node* parent, Edge* edge); //adds an edge from node to child 
    void addAsChild(Node* parent, Node* child, int l, int r); //adds an edge from node to child
    void setSuffixlink(Node* from, Node* to);
    
    
    
    struct Reference{ //Ukkonen, page 8
        //Refers to some state (corresponding some suffix of str) of suffix tree. (possibly state is in the middle of an edge, "implicit state")
        //"add substring of str from l to r to substring corresponding node s"
        //Reference is canonical, if node s is lowest possible
        Node* s; //node
        int l, r; // pointers to string
        Reference(Node* ss, int ll, int rr):s(ss),l(ll),r(rr){}
        Reference(){}
    };
    
    
    //Ukkonen, pages 11,12,13
    Reference update(Reference ref); // follows boundary route from ref (canonical) to end-point
                                     // calls canonize and testAndSplit
                                     // 
    std::pair<bool, Node*> testAndSplit(Reference ref, int chr); //Takes a canonical reference and character which is being appended to str
                                                                 //Makes referenced state explicit by splitting an edge it if needed.
                                                                 //Returns new state and false if it is not an end-point (chr-transition did not exist)
                                                                 //Returns true and new state if is an end-point (chr-transition existed)
    Reference canonize(Reference ref); // Make a reference canonical (Make the node pointed by reference lowest possible)
    
    
    Node root;
    Node aux; // The auxiliary state (Ukkonen, page 3)
    
    Reference activePoint; //Ukkonen, page 9
    
    
public:    
    void push(int chr); // append a single character to the tree
    void push(std::vector<int>& str, int delta=0); // append a  string represented as std::vector<int> to the tree (adds delta to each integer)
    void push(std::string& str, int delta=0);  //append a string represented as std::string to the tree
    
    bool isSubstring(std::vector<int>& str, int delta=0);
    bool isSubstring(std::string& str, int delta=0);
    
    UkkonenTree(){
        for (int i=0; i<sizeOfAlphabet; ++i){ // Add routes for all characters from auxiliary state to the root.
            addAsChild(&aux, &root, -1, i);
        }
        setSuffixlink(&root, &aux); //Suffix link from root to auxiliary state
        activePoint=Reference(&root, 0, -1); //initial active state is root
    }
    
    
    
    std::map<Node*, std::string> names;
    std::string dotFormatDFS(Node* node, std::map<Node*, std::string>& names, int delta=0); // getDotFormat calls this, handles the subtree of node
    std::string getDotFormat(int delta=0); // Returns tree represented in the format used by command line tool dot (which can be used to draw it)
};