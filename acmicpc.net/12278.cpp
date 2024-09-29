#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> v;
map<pii, int> m;
queue<pair<pii, int>> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    q.push({{1,1},0});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.second==16) continue;
        pii curValue = cur.first;
        int pp = curValue.first;
        int qq = curValue.second;
        v.push_back(curValue);
        m[curValue] = v.size();
        q.push({{pp,pp+qq}, cur.second+1});
        q.push({{pp+qq,qq}, cur.second+1});
    }
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        cout << "Case #"<<t<<": ";
        int ch; cin>>ch;
        if(ch==1){
            int n; cin>>n;
            cout << v[n-1].first << " " << v[n-1].second << '\n';
        }
        else {
            int p, q; cin>>p>>q;
            cout << m[{p,q}] << '\n';
        }
    }
}