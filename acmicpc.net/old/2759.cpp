#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> v(n+1);
        vector<int> res;
        for(int i=1; i<=n; ++i){
            cin>>v[i];
        }
        for(int goal=n; goal>=1; --goal){
            if(v[goal]==goal) {
                v.pop_back();
                continue;
            }
            if(v[1]!=goal){
                int idx;
                for(idx=2; idx<goal && v[idx]!=goal; ++idx);
                res.push_back(idx);
                reverse(v.begin()+1, v.begin()+idx+1);
            }
            res.push_back(goal);
            reverse(v.begin()+1, v.end());
            v.pop_back();
        }
        cout << res.size() << '\n';
        for(auto it:res) cout << it << " ";
        cout << '\n';
    }
}