#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MN=100001;
ll C[MN];
ll Ccnt[MN];
int rnk[MN];
struct Edge {
    ll u, v, w;
    Edge(ll u, ll v, ll w):u(u),v(v),w(w){}
};
vector<Edge> edges;
ll p[MN];
unordered_map<ll,ll> m[MN];
ll res[MN];
void init(){
    for(ll i=1; i<MN; ++i){
        p[i]=i;
        m[i][C[i]]=1;
        rnk[i]=1;
    }
}
ll Find(ll x){
    if(p[x]==x) return x;
    return p[x]=Find(p[x]);
}
void Union(ll a, ll b, ll w){
    //cout << "union("<<a<<","<<b<<","<<w<<")\n";
    a=Find(a);
    b=Find(b);
    if(a==b) return;
    if(rnk[a]<rnk[b]){
        swap(a,b);
    }
    //b의 집합을 a로 옮김
    for(auto it=m[b].begin(); it!=m[b].end(); it++){
        //cout << "it : (" << it->first << ", " << it->second << ")\n";
        if(Ccnt[it->first]==it->second) continue;
        res[it->first]+=w*m[a][it->first]*it->second;
        m[a][it->first]+=it->second;
    }
    m[b].clear();
    p[b]=a;
    if(rnk[b]==rnk[a]){
        rnk[a]++;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, K, M; cin>>N>>K>>M;
    for(ll i=1; i<=N; ++i){
        cin>>C[i];
        Ccnt[C[i]]++;
    }
    for(ll i=0; i<M; ++i){
        ll u, v, w; cin>>u>>v>>w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w > b.w;
    });
    init();
    for(auto edge:edges){
        Union(edge.u, edge.v, edge.w);
    }
    for(ll i=1; i<=K; ++i){
        cout << res[i] << '\n';
    }
}