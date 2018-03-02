#include <cxxtest/TestSuite.h>

#include <bits/stdc++.h>
#include <usuffix.h>
#include <vector.h>

class Tests : public CxxTest::TestSuite {
public:
     //Init UkkonenTree of a certain alphabetSize and test if the pointers of root Node are initialized to NULL

    
    //Test if pushing functions modify UkkonenTree::str correctly
    void testPushInt(){
        UkkonenTree u_tree;
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
        UkkonenTree u_tree;
        Vector<int> vec;
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
    void testPushStdString1(){
        UkkonenTree u_tree;
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
    void testPushStdString2(){
        UkkonenTree u_tree;
        std::string str="cocacola";
        int tms=4;
        for (int i=0; i<tms; ++i) u_tree.push(str);
        TS_ASSERT_EQUALS(u_tree.str.size(), tms*str.size());
        
        for (int i=0; i<tms; ++i){
            for (int c=0; c<str.size(); ++c){
                TS_ASSERT_EQUALS(u_tree.str[i*str.size()+c], str[c]);
            }
        }
    }
    void testIsSubstring1(){
        UkkonenTree u_tree;
        std::string str="aaaaaaabbbbbbbbbbcccccccdddddddefghijklmnopq";
        u_tree.push(str);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("cccccc"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("ccccccc"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("cccccccc"), 0);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("cccccccd"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("bccccccd"), 0);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("bcccccccd"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("klmnopq"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("klmnopqa"), 0);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("aaaaaaabbbbbbbbbbcccccccdddddddefghijklmnopq"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("efghijkklmnopq"), 0);
    }


    void testIsSubstring2(){
        UkkonenTree u_tree;
        std::string str="cocoa";
        u_tree.push(str);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("co"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("coc"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("cob"), 0);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("oco"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("coca"), 0);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("ocoa"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("cocoa"), 1);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("cococ"), 0);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("cb"), 0);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("cocoao"), 0);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("cacao"), 0);
    }
    void testIsSubstring3(){
        UkkonenTree u_tree;
        std::string str="abcdefg";
        u_tree.push(str);
        TS_ASSERT_EQUALS(u_tree.isSubstring_("q"), 0);
    }
    
    void testLCS(){
        UkkonenTree u_tree;
        std::string str;
        Vector<int> terminator_positions;
        
        str+="Bacocoa";
        terminator_positions.push_back(str.size());
        str+="0";
        
        str+="cocoaw";
        terminator_positions.push_back(str.size());
        str+="1";
        
        str+="cocoaf";
        terminator_positions.push_back(str.size());
        str+="2";
        
        str+="arcoconima";
        terminator_positions.push_back(str.size());
        str+="3";
        
        str+="ocococococococococococococococo";
        terminator_positions.push_back(str.size());
        str+="4";
        
        u_tree.push(str);
        Pair<int, Vector<int> > lcs=u_tree.findLongestCommonSubstrings(terminator_positions);   
        TS_ASSERT_EQUALS(lcs.first, 4);
        TS_ASSERT_EQUALS(lcs.second.size(), 1);
        std::string ans="";
        for (int i=lcs.second[0]; i<lcs.second[0]+lcs.first; ++i){
            ans+=str[i];
        }
        TS_ASSERT_EQUALS(ans, "coco");
    }
};
