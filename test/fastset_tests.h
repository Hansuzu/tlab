#include <cxxtest/TestSuite.h>

#include <fastset.h>

class Tests : public CxxTest::TestSuite {
public:
     //Init UkkonenTree of a certain alphabetSize and test if the pointers of root Node are initialized to NULL
    void testInsert1(){
        FastSet<int> p;
        p.set_max_element(1e9);
        p.insert_(0);
        p.insert_(1000);
        TS_ASSERT_EQUALS(p.findIndex_(0)>=0, 1);
        TS_ASSERT_EQUALS(p.findByIndex(p.findIndex_(0)), 0);
        TS_ASSERT_EQUALS(p.findIndex_(1000)>=0, 1);
        TS_ASSERT_EQUALS(p.findByIndex(p.findIndex_(1000)), 1000);
        TS_ASSERT_EQUALS(p.findIndex_(1001)<0, 1);
    }
    void testInsert2(){
        FastSet<int> p1;
        FastSet<int> p2;
        p1.set_max_element(1e9);
        p2.set_max_element(1e9);
        p1.insert_(0);
        p1.insert_(1000);
        p1.insert_(5);
        p2.insert_(1);
        p2.insert_(3);
        p2.insert_(200);
        p1.append(p2);
        TS_ASSERT_EQUALS(p1.findIndex_(0)>=0, 1);
        TS_ASSERT_EQUALS(p1.findIndex_(1000)>=0, 1);
        TS_ASSERT_EQUALS(p1.findIndex_(1001)>=0, 0);
        TS_ASSERT_EQUALS(p1.findIndex_(200)>=0, 1);
        TS_ASSERT_EQUALS(p1.findIndex_(1)>=0, 1);
        TS_ASSERT_EQUALS(p1.findIndex_(5)>=0, 1);
        TS_ASSERT_EQUALS(p1.findIndex_(3)>=0, 1);
        TS_ASSERT_EQUALS(p1.findIndex_(2)>=0, 0);
        TS_ASSERT_EQUALS(p1.findIndex_(7)>=0, 0);
    }
};
