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
};
