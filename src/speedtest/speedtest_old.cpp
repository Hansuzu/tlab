//Speed test for old implementation
#include <bits/stdc++.h>
using namespace std;
#include <usuffix_old.h>


UkkonenTree<30> puu30;
UkkonenTree<60> puu60;
UkkonenTree<128> puu128;
UkkonenTree<256> puu256;

pair<int, int> getDif(string& s){
    int mn=1222333;
    int mx=0;
    for (int i=0; i<s.size(); ++i){
        mn=min(mn, (int)s[i]);
        mx=max(mx, (int)s[i]);
    }
    return make_pair(mn, mx-mn+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    pair<int, int> t=getDif(s);
    int minimi=t.first;
    int ero=t.second;
    if (ero<=30){
        puu30.push(s, -minimi);
    }else if (ero<=60){
        puu60.push(s, -minimi);
    }else if (ero<=128){
        puu128.push(s, -minimi);
    }else{
        puu256.push(s, -minimi);
    }
}