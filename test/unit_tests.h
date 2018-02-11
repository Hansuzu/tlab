#include <cxxtest/TestSuite.h>

#include <bits/stdc++.h>
#include "../src/usuffix.cpp"

class Tests : public CxxTest::TestSuite {
public:
     //Init UkkonenTree of a certain alphabetSize and test if the pointers of root Node are initialized to NULL
    void testConstruction1() {
        const int alphabetSize=15;
        UkkonenTree<alphabetSize> u_tree;
        for (int i=0; i<alphabetSize; ++i) TS_ASSERT_EQUALS(u_tree.root.children[i], nullptr);
        TS_ASSERT_EQUALS(u_tree.root.suffixlink, nullptr);
    }
    void testConstruction2() {
        const int alphabetSize=155000;
        UkkonenTree<alphabetSize> u_tree;
        for (int i=0; i<alphabetSize; ++i) TS_ASSERT_EQUALS(u_tree.root.children[i], nullptr);
        TS_ASSERT_EQUALS(u_tree.root.suffixlink, nullptr);
    }
    void testConstruction3() {
        const int alphabetSize=1;
        UkkonenTree<alphabetSize> u_tree;
        for (int i=0; i<alphabetSize; ++i) TS_ASSERT_EQUALS(u_tree.root.children[i], nullptr);
        TS_ASSERT_EQUALS(u_tree.root.suffixlink, nullptr);
    }
    
    //Test if pushing functions modify UkkonenTree::str correctly
    void testPushInt(){
        UkkonenTree<256> u_tree;
        TS_ASSERT_EQUALS(u_tree.str.size(), 0);
        u_tree.push('a');
        u_tree.push('b');
        TS_ASSERT_EQUALS(u_tree.str.size(), 2);
        u_tree.push('c');
        TS_ASSERT_EQUALS(u_tree.str.size(), 3);
        TS_ASSERT_EQUALS(u_tree.str[0], 'a');
        TS_ASSERT_EQUALS(u_tree.str[1], 'b');
        TS_ASSERT_EQUALS(u_tree.str[2], 'c');
    }
    void testPushIntVector(){
        UkkonenTree<256> u_tree;
        std::vector<int> vec;
        for (int i=0; i<10; ++i) vec.push_back(i);
        u_tree.push(vec);
        TS_ASSERT_EQUALS(u_tree.str.size(), 10);
        for (int i=0; i<10; ++i) vec[i]=10+i;
        u_tree.push(vec);
        TS_ASSERT_EQUALS(u_tree.str.size(), 20);
        for (int i=0; i<20; ++i){
            TS_ASSERT_EQUALS(u_tree.str[i], i);
        }
    }
    void testPushStdString(){
        UkkonenTree<256> u_tree;
        std::string str="abcde";
        int tms=4;
        for (int i=0; i<tms; ++i) u_tree.push(str);
        TS_ASSERT_EQUALS(u_tree.str.size(), tms*str.size());
        
        for (int i=0; i<tms; ++i){
            for (int c=0; c<str.size(); ++c){
                TS_ASSERT_EQUALS(u_tree.str[i*str.size()+c], str[c]);
            }
        }
    }
    
    
    void testAddChild1(){
        UkkonenTree<256> u_tree;
        std::string str="abcdefg";
        u_tree.push(str);
        UkkonenTree<256>::Node* node1=new UkkonenTree<256>::Node;
        UkkonenTree<256>::Node* node2=u_tree.addChild(node1,  3, 5);
        TS_ASSERT_EQUALS(node1->children[str[3]]->targetNode, node2);
        for (int i=0; i<256; ++i){
            if (i!=str[3]) TS_ASSERT_EQUALS(node1->children[i],nullptr);
        }
    }
    void testAddChild2(){
        UkkonenTree<256> u_tree;
        UkkonenTree<256>::Node* node1=new UkkonenTree<256>::Node;
        UkkonenTree<256>::Node* node2=u_tree.addChild(node1,  -1, 5);
        TS_ASSERT_EQUALS(node1->children[5]->targetNode, node2);
        for (int i=0; i<256; ++i){
            if (i!=5)TS_ASSERT_EQUALS(node1->children[i],nullptr);
        }
    }
    
    void testAddAsChild1(){
        UkkonenTree<256> u_tree;
        std::string str="abcdefg";
        u_tree.push(str);
        UkkonenTree<256>::Node* node1=new UkkonenTree<256>::Node;
        UkkonenTree<256>::Node* node2=new UkkonenTree<256>::Node;
        u_tree.addAsChild(node1, node2, 3, 5);
        TS_ASSERT_EQUALS(node1->children[str[3]]->targetNode, node2);
        for (int i=0; i<256; ++i){
            if (i!=str[3]) TS_ASSERT_EQUALS(node1->children[i],nullptr);
        }
    }
    void testAddAsChild2(){
        UkkonenTree<256> u_tree;
        UkkonenTree<256>::Node* node1=new UkkonenTree<256>::Node;
        UkkonenTree<256>::Node* node2=new UkkonenTree<256>::Node;
        u_tree.addAsChild(node1, node2, -1, 19);
        TS_ASSERT_EQUALS(node1->children[19]->targetNode, node2);
        for (int i=0; i<256; ++i){
            if (i!=19) TS_ASSERT_EQUALS(node1->children[i],nullptr);
        }
    }
    
    void testAux(){
        UkkonenTree<119> u_tree;
        for (int i=0; i<119; ++i){
            TS_ASSERT_EQUALS(u_tree.aux.children[i]->targetNode, &(u_tree.root));
        }
    }
    

};
