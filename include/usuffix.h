#include <vector.h>
#include <bitset.h>
#include <pair.h>


#include <vector>
#include <string> //std::string, used 
#include <map> //std::map, used in drawing (could be replaced with something else)

#ifndef USUFFIX_H
#define USUFFIX_H


//Ukkonen's paper: https://www.cs.helsinki.fi/u/ukkonen/SuffixT1withFigs.pdf



//Integers in range 0,1,...,sizeOfAlphabet-1 will be used as alphabet.




class UkkonenTree{

public: //everything public to make unit testing easy
    //

    Vector<int> str; //The current string (represented as a vector of integers)
    //Characters are assumed to be greater than or equal to zero.
    
    struct Node; //implemented in usuffixnode*.cpp-file
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
        //FastSet and set uses this
        bool operator<(const Edge& o) const{
            return firstCharacter<o.firstCharacter;
        }
    };
    
    void calcFirstCharacter(Edge& edge); //Calculate the first character of an edge
    
    Node* addChild(Node* node, int l, int r, int index); //creates new child node for a node, returns a pointer to the newly created node
    
    
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
    
    int childIndex(Reference& ref);
    
    
    //Ukkonen, pages 11,12,13
    void update(Reference& ref); // follows boundary route from ref (canonical) to end-point
                                     // calls canonize and testAndSplit
                                     // 
    Pair<bool, Node*> testAndSplit(Reference& ref, int chr); //Takes a canonical reference and character which is being appended to str
                                                                 //Makes referenced state explicit by splitting an edge it if needed.
                                                                 //Returns new state and <0 if it is not an end-point (chr-transition did not exist)
                                                                 //Returned value is a index where chr-transition can be inserted
                                                                 //Returns 0 and new state if is an end-point (chr-transition existed)
    void canonize(Reference& ref); // Make a reference canonical (Make the node pointed by reference lowest possible)
    
    
    Node* root;
    Node* aux; // The auxiliary state (Ukkonen, page 3)
    
    Reference activePoint; //Ukkonen, page 9
    
    
public:    
    void push(int chr); // append a single character to the tree
    void push(Vector<int>& astr, int delta=0); // append a  string represented as std::vector<int> to the tree (adds delta to each integer)
    void push(std::string& astr, int delta=0);  //append a string represented as std::string to the tree
    
    
    Reference getChild(Reference ref, int c); // If there exist a state ref+c, return canonized reference to it. If fail, returned Reference.s=NULL
    
    bool isSubstring(Vector<int>& astr, int delta=0);
    bool isSubstring(std::string& astr, int delta=0);
    
    
    
    //LCS -recursive search
    bool findCSNodes(Node* position, Bitset& currentState, Vector<int>& terminator_positions, Vector<Pair<Node*, Pair<int, int> > >& positions, int depth, int last_character); //Find recursively deepest nodes that are substrings of all strings
    
    Pair<int, Vector<int> > findLongestCommonSubstrings(Vector<int> terminator_positions); 
    //^Returns length of longest common substring and some start-positions of them
    //terminator_positions is the positions of the terminator-characters separating different strings.
    //terminator_positions is assumed to be sorted in increasing order,
    //For example for strings abbaba, abba and bbab the tree could be made of string  abbaba$abba#bbab%
    //The terminator positions would then be 6, 11 and 16
    //Algorithm would return number 3 (length of LCS) and Vector of size 1. The index in vector could be 1, 8 or 12 (the positions of the LCS bba)
    //If there were multiple different longest common substrings, the Vector would contain one index pointing each of them
    //Works in O(n*m) where n is the total size of string in tree and m is the number of strings
    
    
    UkkonenTree();
    
    
    
    //For drawing only, these contain std::functinos.
    std::map<Node*, std::string> dnames;
    std::string dotFormatDFS(Node* node, std::map<Node*, std::string>& names, int delta=0); // getDotFormat calls this, handles the subtree of node
    std::string getDotFormat(int delta=0); // Returns tree represented in the format used by command line tool dot (which can be used to draw it)
};


#endif