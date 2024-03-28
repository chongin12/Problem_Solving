#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> G[250011];
vector<ll> nodes;
ll p[250011];
ll sz[250011];
ll parent[250011];
bool isInSet[250011];
ll Find(ll x){
    if(x==p[x]) return x;
    return p[x]=Find(p[x]);
}
void Union(ll a, ll b){
    a=Find(a);
    b=Find(b);
    if(a==b) return;
    sz[a]+=sz[b];
    sz[b]=0;
    p[b]=a;
}
void initx(ll x){
    p[x]=0;
    sz[x]=0;
    isInSet[x]=false;
}
void dfs(ll x, ll prv){
    for(auto it:G[x]){
        if(it==prv) continue;
        parent[it]=x;
        dfs(it,x);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N-1; ++i){
        ll u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll Q; cin>>Q;
    parent[1]=1;
    dfs(1, -1);
    while(Q--){
        ll K; cin>>K;
        nodes.clear();
        for(ll i=0; i<K; ++i){
            ll a; cin>>a;
            nodes.push_back(a);
            p[a]=a;
            sz[a]=1;
            isInSet[a]=true;
        }
        for(auto it:nodes){
            if(isInSet[it] && isInSet[parent[it]]){
                Union(it, parent[it]);
            }
        }
        ll res=0;
        for(auto it:nodes){
            if(sz[it]>=2){
                res+=sz[it]*(sz[it]-1)/2;
            }
            initx(it);
        }
        cout << res << '\n';
    }
}