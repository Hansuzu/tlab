#include <bits/stdc++.h>
#include <usuffix.h>

using namespace std;

/*

string longestCommonSubString(string& a, string& b){ // Find the longest common substring in O(n) of two strings consisting of alphabet [a-z]
    UkkonenTree<30> eppapuu;
    vector<int> t;
    for (auto c : a) t.push_back(c-'a'+2);
    t.push_back(1);
    for (auto c : b) t.push_back(c-'a'+2);
    t.push_back(0);
    eppapuu.push(t);
    
}*/


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    UkkonenTree<30> eppapuu;
    string s;
    cin >> s;
    eppapuu.push(s, -'a');
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        string b;
        cin >> b;
        cout << eppapuu.isSubstring(b, -'a') << "\n";
    }
   // cout << eppapuu.getDotFormat('a') << std::endl;
}