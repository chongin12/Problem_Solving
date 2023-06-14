#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF = 1e18;
struct Edge {
    ll u, v, w;
    Edge(ll u, ll v, ll w):u(u),v(v),w(w){}
};
vector<Edge> edges;
ll money[1000];
ll dist[1000];
vector<int> rG[1000];
int canReach[1000];
void dfs(int u){
    if(canReach[u]) return;
    canReach[u]=1;
    for(auto it:rG[u]){
        dfs(it);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, S, T, M; cin>>N>>S>>T>>M;
    for(int i=0; i<M; ++i){
        ll u,v,w; cin>>u>>v>>w;
        edges.push_back({u,v,w});
        rG[v].push_back(u);
    }
    dfs(T);
    for(int i=0; i<N; ++i){
        cin>>money[i];
    }
    for(int i=0; i<N; ++i){
        dist[i]=-INF;
    }
    dist[S]=money[S];
    for(auto &it:edges){
        it.w = -it.w + money[it.v];
    }
    for(int i=0; i<M; ++i){
        // for(int i=0; i<N; ++i){
        //     cout << "dist["<<i<<"]="<<dist[i]<<'\n';
        // }
        // cout << '\n';
        for(auto edge:edges){
            if(dist[edge.u] == -INF) continue;
            dist[edge.v] = max(dist[edge.v], dist[edge.u]+edge.w);
        }
    }
    bool flag = true;
    for(auto edge:edges){
        if(dist[edge.u] == -INF) continue;
        if(dist[edge.v] < dist[edge.u]+edge.w && canReach[edge.v]){
            flag=false; break;
        }
    }
    if(dist[T]==-INF){
        cout << "gg\n";
    }
    else if(!flag) {
        cout << "Gee\n";
    }
    else{
        cout << dist[T] << '\n';
    }
}