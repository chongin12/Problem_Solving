#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
vector<pii> v;
struct Edge {
    ll u, v;
    long double w;
};
vector<Edge> edges;
ll par[1001];
void init(){
    for(ll i=0; i<1001; ++i){
        par[i]=i;
    }
}
ll Find(ll x){
    if(par[x]==x) return x;
    return par[x]=Find(par[x]);
}
void Union(ll a, ll b){
    a=Find(a);
    b=Find(b);
    par[a]=b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    ll N, M; cin>>N>>M;
    for(ll i=0; i<N; ++i){
        ll X, Y; cin>>X>>Y;
        v.push_back({X, Y});
    }
    for(ll i=0; i<N; ++i){
        for(ll j=i+1; j<N; ++j){
            pii A=v[i];
            pii B=v[j];
            ll k=(A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second);
            edges.push_back({i, j, sqrt(k)});
        }
    }
    for(ll i=0; i<M; ++i){
        ll a, b; cin>>a>>b; a--,b--;
        Union(a,b);
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    long double ret=0;
    for(auto edge:edges){
        if(Find(edge.u)==Find(edge.v)) continue;
        ret+=edge.w;
        Union(edge.u, edge.v);
    }
    cout << fixed;
    cout.precision(2);
    cout << ret << '\n';
}