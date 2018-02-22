#include <cxxtest/TestSuite.h>

#include <vector.h>

class Tests : public CxxTest::TestSuite {
public:
     //Init UkkonenTree of a certain alphabetSize and test if the pointers of root Node are initialized to NULL
    void testInsert1(){
        vector<int> p;
        p.push_back(1);
        p.push_back(2);
        p.push_back(0);
        TS_ASSERT_EQUALS(p.size(), 3);
        TS_ASSERT_EQUALS(p[0], 1);
        TS_ASSERT_EQUALS(p[1], 2);
        TS_ASSERT_EQUALS(p[2], 0);
    }
    void testAccess(){
        vector<int> p;
        p.push_back(1);
        p.push_back(2);
        p.push_back(0);
        p[0]=5;
        TS_ASSERT_EQUALS(p[0], 5);
        int t=p[1];
        TS_ASSERT_EQUALS(t, 2);
        TS_ASSERT_EQUALS(p[1], 2);
    }
    void testLargeArray(){
        vector<int> p;
        for (int i=0; i<1000000; ++i){
            p.push_back(i);
        }
        for (int i=0; i<1000000; ++i){
            TS_ASSERT_EQUALS(p[i], i);
            p[i]=-i;
        }
        for (int i=0; i<1000000; ++i){
            TS_ASSERT_EQUALS(p[i], -i);
        }
    }
    void test_resize(){
        vector<int> p;
        p.resize(2500);
        for (int i=0; i<2500; ++i) p[i]=2;
        for (int i=0; i<2500; ++i) TS_ASSERT_EQUALS(p[i], 2);
    }
    
    void test_swap(){
        vector<int> p1;
        vector<int> p2;
        for (int i=0; i<200; ++i) p1.push_back(i);
        for (int i=0; i<4000; ++i) p2.push_back(-i);
        p1.swap(p2);
        for (int i=0; i<4000; ++i) TS_ASSERT_EQUALS(p1[i], -i);
        for (int i=0; i<200; ++i) TS_ASSERT_EQUALS(p2[i], i);
        p2.clear();
        p2.shrink_to_fit();
        p2.swap(p1);
        for (int i=0; i<200; ++i) TS_ASSERT_EQUALS(p2[i], -i);
        p1.push_back(13);
        TS_ASSERT_EQUALS(p1.size(), 1);
        TS_ASSERT_EQUALS(p1[0], 13);
    }
};