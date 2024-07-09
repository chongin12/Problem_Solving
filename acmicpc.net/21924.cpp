#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Node {
    ll u, v, w;
};
ll par[100001];
void init() {
    for(ll i=0; i<100001; ++i){
        par[i]=i;
    }
}
ll Find(ll x){
    if(par[x]==x) return x;
    return par[x]=Find(par[x]);
}
void Unite(ll a, ll b){
    a=Find(a);
    b=Find(b);
    if(a==b) return;
    par[a]=b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, M; cin>>N>>M;
    vector<Node> edges;
    ll sum=0;
    init();
    for(ll i=0; i<M; ++i){
        ll a, b, c; cin>>a>>b>>c;
        edges.push_back({a,b,c});
        sum+=c;
    }
    sort(edges.begin(), edges.end(), [](Node A, Node B){
        return A.w < B.w;
    });
    ll res=0;
    for(auto it:edges){
        if(Find(it.u)!=Find(it.v)){
            res+=it.w;
            Unite(it.u, it.v);
        }
    }
    bool flag=true;
    for(ll i=2; i<=N; ++i){
        if(Find(1)!=Find(i)) {
            flag=false;
            break;
        }
    }
    if(!flag) cout << "-1\n";
    else cout << sum-res << '\n';
}