#include <cxxtest/TestSuite.h>

#include "../src/usuffix.cpp"

class Test1 : public CxxTest::TestSuite {
public:
     //Init UkkonenTree of a certain alphabetSize and test if the pointers of root Node are initialized to NULL
    void testConstruction1(void) {
        const int alphabetSize=15;
        UkkonenTree<alphabetSize> u_tree;
        for (int i=0; i<alphabetSize; ++i) TS_ASSERT_EQUALS(u_tree.root.children[i], (void*)NULL);
        TS_ASSERT_EQUALS(u_tree.root.suffixlink, (void*)NULL);
    }
    void testConstruction2(void) {
        const int alphabetSize=155000;
        UkkonenTree<alphabetSize> u_tree;
        for (int i=0; i<alphabetSize; ++i) TS_ASSERT_EQUALS(u_tree.root.children[i], (void*)NULL);
        TS_ASSERT_EQUALS(u_tree.root.suffixlink, (void*)NULL);
    }
    void testConstruction3(void) {
        const int alphabetSize=1;
        UkkonenTree<alphabetSize> u_tree;
        for (int i=0; i<alphabetSize; ++i) TS_ASSERT_EQUALS(u_tree.root.children[i], (void*)NULL);
        TS_ASSERT_EQUALS(u_tree.root.suffixlink, (void*)NULL);
    }
    
    
};
