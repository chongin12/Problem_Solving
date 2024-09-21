#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        ll n, c; cin>>n>>c;
        vector<ll> v(n+10);
        vector<int> G[200011];
        priority_queue<pll> pq;
        for(ll i=0; i<n; ++i){
            ll a; cin>>a;
            v[i+1]=a;
            pq.push({a,i+1});
        }
        for(int i=0; i<n-1; ++i){
            int u, v; cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<ll> gain;
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int curNode=cur.second;
            cout << "curNode : " << curNode << ", v_cur = " << v[curNode] << '\n';
            if(G[curNode].size()*c<v[curNode]){
                gain.push_back(curNode);
                for(auto it:G[curNode]){
                    v[it]-=c;
                }
            }
        }
        ll res=0;
        for(auto it:gain){
            res+=max(0LL,v[it]);
        }
        cout << res << '\n';
    }
}