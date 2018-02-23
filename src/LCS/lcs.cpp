#include <iostream>
#include <usuffix.h>
#include <vector.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    Vector<int> syote;
    int terminator=300;
    Vector<int> terminator_positions;
    for (int i=0; i<n; ++i){
        string s;
        cin >> s;
        for (int j=0; j<(int)s.size(); ++j) syote.push_back(s[j]);
        
        terminator_positions.push_back(syote.size());
        syote.push_back(terminator++);
    }
    
    UkkonenTree eppapuu;
    eppapuu.push(syote);
    
    Pair<int, Vector<int> > res=eppapuu.findLongestCommonSubstrings(terminator_positions);
    std::cout << res.first << "\n";
    std::cout << res.second.size() << "\n";
    for (int i=0; i<(int)res.second.size(); ++i){
        int p=res.second[i];
        std::string s;
        for (int j=0; j<(int)res.first; ++j){
            s.push_back(syote[p+j]);
        }
        std::cout << s << "\n";
    }
}