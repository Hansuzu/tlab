#include <cxxtest/TestSuite.h>

#include <bitset.h>

class Tests : public CxxTest::TestSuite {
public:
     //Init UkkonenTree of a certain alphabetSize and test if the pointers of root Node are initialized to NULL
    void testInsert(){
        Bitset a(50);
        a.setBitOn(14);
        a.setBitOn(16);
        a.setBitOff(16);
        a.setBitOn(19);
        for (int i=0; i<50; ++i){
            bool expected=0;
            if (i==14 || i==19) expected=1;
            TS_ASSERT_EQUALS(a.getBit(i), expected);
        }
    }
    void testAnd(){
        Bitset a(50);
        a.setBitOn(14);
        a.setBitOn(16);
        a.setBitOff(12);
        a.setBitOff(16);
        a.setBitOn(19);
        a.setBitOn(45);
        //a: bits 14, 19 and 45
        Bitset b(50);
        b.setBitOn(14);
        b.setBitOn(15);
        b.setBitOn(0);
        b.setBitOn(2);
        b.setBitOn(16);
        b.setBitOn(19);
        //b: bits 0, 2, 14, 15, 16, 19
        a&=b; //should be bits 14 and 19
        for (int i=0; i<50; ++i){
            bool expected=0;
            if (i==14 || i==19) expected=1;
            TS_ASSERT_EQUALS(a.getBit(i), expected);
        }
    }
    void testOr(){
        Bitset a(50);
        a.setBitOn(14);
        a.setBitOn(16);
        a.setBitOff(12);
        a.setBitOff(16);
        a.setBitOn(19);
        a.setBitOn(45);
        //a: bits 14, 19 and 45
        Bitset b(50);
        b.setBitOn(14);
        b.setBitOn(15);
        b.setBitOn(0);
        b.setBitOn(2);
        b.setBitOn(16);
        b.setBitOn(19);
        //b: bits 0, 2, 14, 15, 16, 19
        a|=b;
        for (int i=0; i<50; ++i){
            bool expected=0;
            if (i==0 || i==2 || i==14 || i==15 || i==16 || i==19 || i==45) expected=1;
            TS_ASSERT_EQUALS(a.getBit(i), expected);
        }
    }
    
    void testPopcount(){
        Bitset a(50);
        a.setBitOn(14);
        a.setBitOn(16);
        a.setBitOff(12);
        a.setBitOff(16);
        a.setBitOn(19);
        a.setBitOn(45);
        //a: bits 14, 19 and 45
        TS_ASSERT_EQUALS(a.popcount(), 3);
        Bitset b(50);
        b.setBitOn(14);
        b.setBitOn(15);
        b.setBitOn(0);
        b.setBitOn(2);
        b.setBitOn(16);
        b.setBitOn(19);
        //b: bits 0, 2, 14, 15, 16, 19
        TS_ASSERT_EQUALS(b.popcount(), 6);
        Bitset c(b);
        TS_ASSERT_EQUALS(c.popcount(), 6);
        TS_ASSERT_EQUALS((a&c).popcount(), 2);
        TS_ASSERT_EQUALS((a|c).popcount(), 7);
        b=a;
        TS_ASSERT_EQUALS((b&c).popcount(), 2);
        TS_ASSERT_EQUALS((b|c).popcount(), 7);
    }
};