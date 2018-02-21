#include <bits/stdc++.h>
using namespace std;


bool isSubstring(string& s, string& f){
    return s.find(f)!=string::npos;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        string b;
        cin >> b;
        cout << isSubstring(s, b) << "\n";
    }
   // cout << e
}