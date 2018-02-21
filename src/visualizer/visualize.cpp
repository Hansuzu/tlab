#include <bits/stdc++.h>
#include <usuffix.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    UkkonenTree eppapuu;
    string s;
    cin >> s;
    eppapuu.push(s, -'a');
    ofstream data("tree");
    data<<eppapuu.getDotFormat('a');
    data.close();
    return system("dot tree -Tpng > tree.png");
}