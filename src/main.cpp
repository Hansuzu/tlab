#include <bits/stdc++.h>
#include <usuffix.h>
#include <fastset.h>
using namespace std;


FastSet<int> fset;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    FastSet<UkkonenTree::Edge> fset2;
    UkkonenTree::Edge edge1(NULL, 0, 0); edge1.firstCharacter=5;
    UkkonenTree::Edge edge2(NULL, 0, 0); edge2.firstCharacter=9;
    UkkonenTree::Edge edge3(NULL, 0, 0); edge3.firstCharacter=2;
    fset2.insert(edge1);
    fset2.insert(edge2);
    fset2.insert(edge3);
    for (int i=0; i<10; ++i){
        UkkonenTree::Edge fedge(NULL, 0, 0); fedge.firstCharacter=i;
        int id=fset2.findIndex(fedge);
        cout << i << ": " << id;
        if (id>=0) cout << ", " << fset2.findByIndex(id).firstCharacter;
        cout << endl;
    }
}
