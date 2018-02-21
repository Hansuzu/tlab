#include <bits/stdc++.h>
using namespace std;
#include <usuffix.h>

UkkonenTree::Edge e[(int)22e6+5];

UkkonenTree::Node* nodes[(int)8e6+5];
void sett(int v, UkkonenTree::Edge& ed){
    e[v]=ed;
}
void test(int v){ v&=(1<<24)-1;
    e[v].l+=v;
    e[v].r-=v-2;
    UkkonenTree::Edge ed=e[v];
    sett(v+1, ed);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    UkkonenTree eppapuu;
    string s;
    cin >> s;
    eppapuu.push(s);
}