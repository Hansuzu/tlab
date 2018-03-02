#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> strs;

bool is_substring(int a, int b, int stri){
    for (int i=0; i+(b-a)<(int)strs[stri].size(); ++i){
        bool ok=1;
        for (int j=0; j<=(b-a); ++j){
            if (strs[stri][i+j]!=strs[0][a+j]){
                ok=0;
                break;
            }
        }
        if (ok) return 1;
    }
    return 0;
}

vector<string> ans;

int solve(){
    string s=strs[0];
    for (int length=strs[0].size(); length>0; --length){
        for (int i=0; i+length-1<(int)strs[0].size(); ++i){
            int j=i+length-1;
            bool ia=1;
            for (int k=1; k<(int)strs.size(); ++k){
                if (!is_substring(i, j, k)){
                    ia=0;
                    break;
                }
            }
            if (ia){
                ans.push_back(strs[0].substr(i, length));
            }
        }
        if (ans.size()) return length;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i){
        string s;
        cin >> s;
        strs.push_back(s);
    }
    cout << solve() << "\n";
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << "\n";
    for (auto s : ans) cout << s << "\n";
}