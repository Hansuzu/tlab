//Speed test for old implementation
#include <bits/stdc++.h>
using namespace std;
int SZ=10;
int MX=32;



int main(int argc, char** argv){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0; i<argc; ++i){
        if (argv[i][0]=='Z'){
            string s(&argv[i][1]);
            SZ=stoi(s);
        }else if (argv[i][0]=='X'){
            string s(&argv[i][1]);
            MX=stoi(s);            
        }
    }
    cout << SZ << "\n";
    for (int i=0; i<SZ; ++i){
        cout << rand()%MX << " ";
    }
    cout << "\n";
}
