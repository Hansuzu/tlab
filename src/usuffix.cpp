#include <bits/stdc++.h>
#include <usuffix.h> 

//Node constructor
template<int sizeOfAlphabet> UkkonenTree<sizeOfAlphabet>::Node::Node(){
    memset(children, 0, sizeOfAlphabet*sizeof(Node*));
    suffixlink=0;
}
//Node destructor
template<int sizeOfAlphabet> UkkonenTree<sizeOfAlphabet>::Node::~Node(){
      
}




