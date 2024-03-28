#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll par[100001];
ll cnt[100001];
struct edge {
    ll u, v, w;
    edge(ll u, ll v, ll w):u(u),v(v),w(w){}
};
void init(){
    for(ll i=0; i<100001; ++i){
        par[i]=i;
        cnt[i]=1;
    }
}
ll Find(ll x){
    if(par[x]==x) return x;
    return par[x]=Find(par[x]);
}
void Union(ll a, ll b){
    a=Find(a);
    b=Find(b);
    if(a==b) return;
    cnt[b]=cnt[a]+cnt[b];
    par[a]=b;
}
vector<edge> edges;
int main(){
    init();
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    ll total=0;
    ll res=0;
    for(int i=0; i<M; ++i){
        ll u, v, w; cin>>u>>v>>w;
        edges.push_back(edge(u,v,w));
        total+=w;
    }
    sort(edges.begin(), edges.end(), [](edge a, edge b){
        return a.w>b.w;
    });
    for(auto it:edges){
        ll u=it.u, v=it.v, w=it.w;
        if(Find(u)!=Find(v)){
            // cout << "u : " << u << ", v : " << v << ", res+="<< total << " * " << cnt[Find(u)]*cnt[Find(v)] << '\n';
            res+=total*cnt[Find(u)]*cnt[Find(v)];
            res%=1000000000;
        }
        Union(u,v);
        total-=w;
    }
    cout << res%1000000000 << '\n';
}