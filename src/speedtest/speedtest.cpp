#include <iostream>
//Speedtests for other implementations but array
#include <usuffix.h>
#include <vector.h>
using namespace std;
int n;
Vector<int> s;

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