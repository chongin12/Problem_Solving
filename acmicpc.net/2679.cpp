#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MN = 1001;
vector<int> G[MN];
vector<pii> Gdijk[MN];
int c[MN][MN], f[MN][MN], dist[MN];
const int INF = 987654321;
void init(){
    for(int i=0; i<MN; ++i){
        G[i].clear();
        Gdijk[i].clear();
        dist[i]=-1;
        for(int j=0; j<MN; ++j){
            c[i][j]=0;
            f[i][j]=0;
        }
    }
}
int MaxFlow(int src, int snk){
    int ret=0;
    while(1){
        queue<int> q; q.push(src);
        vector<int> p(MN, -1); p[src]=src;
        while(!q.empty() && p[snk]==-1){
            int cur = q.front(); q.pop();
            for(auto nxt:G[cur]){
                if(p[nxt]!=-1 || c[cur][nxt]-f[cur][nxt]==0) continue;
                p[nxt]=cur;
                q.push(nxt);
            }
        }
        if(p[snk]==-1) break;
        int flow = 1987654321;
        for(int k=snk; k!=src; k=p[k]){
            flow = min(flow, c[p[k]][k]-f[p[k]][k]);
        }
        for(int k=snk; k!=src; k=p[k]){
            f[p[k]][k] += flow;
            f[k][p[k]] -= flow;
        }
        ret+=flow;
    }
    return ret;
}
void Dijkstra(int src) {
    dist[src] = INF;
    priority_queue<pii> pq; pq.push({dist[src], src});
    while(!pq.empty()){
        pii curNode = pq.top(); pq.pop();
        int cur = curNode.second;
        if(curNode.first < dist[cur]) continue;
        for(auto it:Gdijk[cur]){
            int nxt = it.first;
            int w = min(it.second, dist[cur]);
            if(dist[nxt]==-1 || dist[nxt] < w){
                dist[nxt] = w;
                pq.push({w, nxt});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        init();
        int N, E, S, T; cin>>N>>E>>S>>T;
        for(int i=0; i<E; ++i){
            int u, v, w; cin>>u>>v>>w;
            G[u].push_back(v);
            G[v].push_back(u);
            c[u][v]=w;
            Gdijk[u].push_back({v,w});
        }
        int maxFlow = MaxFlow(S, T);
        // cout << maxFlow << '\n';
        Dijkstra(S);
        // cout << dist[T] << '\n';
        cout << fixed;
        cout.precision(3);
        // if(dist[T]==0 || dist[T]==-1) cout << 0.000 << '\n';
        cout << (double)maxFlow / dist[T] << '\n';
    }
}