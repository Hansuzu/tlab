//Speed test for array -implementation
#include <usuffix_array.h>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s;

UkkonenTree<2> puu2;
UkkonenTree<4> puu4;
UkkonenTree<8> puu8;
UkkonenTree<16> puu16;
UkkonenTree<32> puu32;
UkkonenTree<64> puu64;
UkkonenTree<128> puu128;
UkkonenTree<256> puu256;
UkkonenTree<512> puu512;
UkkonenTree<1024> puu1024;

pair<int, int> getDif(){
    int mn=1222333;
    int mx=0;
    for (int i=0; i<s.size(); ++i){
        mn=min(mn, s[i]);
        mx=max(mx, s[i]);
    }
    return make_pair(mn, mx-mn+1);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i){
        int v;
        cin >> v;
        s.push_back(v);
    }
    pair<int, int> t=getDif();
    int minimi=t.first;
    int ero=t.second;
    if (ero<=2){
        puu2.push(s, -minimi);
    }else if (ero<=4){
        puu4.push(s, -minimi);
    }else if (ero<=8){
        puu8.push(s, -minimi);
    }else if (ero<=16){
        puu16.push(s, -minimi);
    }else if (ero<=32){
        puu32.push(s, -minimi);
    }else if (ero<=64){
        puu64.push(s, -minimi);
    }else if (ero<=128){
        puu128.push(s, -minimi);
    }else if (ero<=256){
        puu256.push(s, -minimi);
    }else if (ero<=512){
        puu512.push(s, -minimi);
    }else if (ero<=1024){
        puu1024.push(s, -minimi);
    }
}
