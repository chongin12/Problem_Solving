#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
const ll HO=200001;
const ll INF = 1e18;
vector<pii> G[400010];
vector<ll> d1(400010, INF), d2(400010, INF);
void init(int n){
    for(int i=1; i<=n; ++i){
        G[i].clear();
        G[i+HO].clear();
        d1[i]=INF;
        d2[i]=INF;
        d1[i+HO]=INF;
        d2[i+HO]=INF;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    while(T--){
        ll n, m, h; cin>>n>>m>>h;
        for(ll i=0; i<h; ++i){
            ll a; cin>>a;
            G[a].push_back({a+HO, 0});
        }
        for(ll i=0; i<m; ++i){
            ll u, v, w; cin>>u>>v>>w;
            G[u].push_back({v,w});
            G[v].push_back({u,w});
            G[u+HO].push_back({v+HO, w/2});
            G[v+HO].push_back({u+HO, w/2});
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // start from 1
        pq.push({0,1});
        d1[1]=0;
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            // cout << "curNode : " << cur.second << ", curDist = " << cur.first << '\n';
            auto curNode = cur.second;
            auto curDist = cur.first;
            if(d1[curNode]!=curDist) continue;
            for(auto it:G[curNode]){
                if(curDist+it.second<d1[it.first]){
                    d1[it.first]=curDist+it.second;
                    pq.push({curDist+it.second, it.first});
                }
            }
        }
        pq.push({0,n});
        d2[n]=0;
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            auto curNode = cur.second;
            auto curDist = cur.first;
            if(d2[curNode]!=curDist) continue;
            for(auto it:G[curNode]){
                if(curDist+it.second<d2[it.first]){
                    d2[it.first]=curDist+it.second;
                    pq.push({curDist+it.second, it.first});
                }
            }
        }
        ll res=INF;
        for(ll i=1; i<=n; ++i){
            res=min({res,max(d1[i],d2[i]), max(d1[i+HO],d2[i]), max(d1[i],d2[i+HO]), max(d1[i+HO],d2[i+HO])});
        }
        // for(int i=1; i<=3; ++i){
        //     cout << d1[i] << " ";
        // }
        // cout << '\n';
        // for(int i=1; i<=3; ++i){
        //     cout << d1[i+HO] << " ";
        // }
        // cout << '\n';
        // for(int i=1; i<=3; ++i){
        //     cout << d2[i] << " ";
        // }
        // cout << '\n';
        // for(int i=1; i<=3; ++i){
        //     cout << d2[i+HO] << " ";
        // }
        // cout << "\n--------\n";
        if(res==INF) cout << "-1\n";
        else cout << res << '\n';

        init(n);
    }
}