#include <bits/stdc++.h>

template<int sizeOfAlphabet> class UkkonenTree{
    struct Node {
        Node* children[sizeOfAlphabet]; //Array of child nodes, finding a child works in O(1)
        Node* suffixlink; //Suffix link pointer
        
        //constructor and destructor (defined in usuffix.cpp)
        Node(); 
        ~Node();
    };
    
public:
    
    Node root;
};