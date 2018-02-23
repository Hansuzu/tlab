#include <cxxtest/TestSuite.h>

#include <pair.h>

class Tests : public CxxTest::TestSuite {
public:
     //Init UkkonenTree of a certain alphabetSize and test if the pointers of root Node are initialized to NULL
    void testIntInt(){
        Pair<int, int> t;
        t.first=3;
        t.second=6;
        TS_ASSERT_EQUALS(t.first, 3);
        TS_ASSERT_EQUALS(t.second, 6);
    }
};
