#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int> > v;
    for(int i=0; i<8; ++i){
        int a; cin>>a; v.push_back({a,i+1});
    }
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    vector<int> vv;
    int res=0;
    for(int i=0; i<5; ++i){
        res+=v[i].first;
        vv.push_back(v[i].second);
    }
    cout << res << '\n';
    sort(vv.begin(), vv.end());
    for(auto it:vv){ cout << it << ' '; }
    cout << '\n';
}