//Speedtests for vector implementations (linear and binary_search)
#include <usuffix.h>
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> s;

UkkonenTree eppapuu;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i){
        int t;
        cin >> t;
        s.push_back(t);
    }
    eppapuu.push(s);
}