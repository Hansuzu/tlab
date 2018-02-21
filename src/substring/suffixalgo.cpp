#include <bits/stdc++.h>
#include <usuffix.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    UkkonenTree eppapuu;
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
}