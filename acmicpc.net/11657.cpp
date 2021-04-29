#include <iostream>
#include <vector>
#define INF 98765432100
using namespace std;
using ll = long long int;
struct edge{
    int u, v;
    edge(int u, int v) : u(u), v(v) {}
};
ll G[501][501];
ll dist[501];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<501; ++i){
        for(int j=0; j<501; ++j){
            G[i][j] = INF;
        }
        dist[i] = INF;
    }
    vector<edge> EG;
    int N, M; cin >> N >> M;
    for(int i=0; i<M; ++i){
        int a, b;
        ll c; cin >> a >> b >> c;
        if(G[a][b]==INF) EG.push_back(edge(a,b));
        if(G[a][b]>c) G[a][b] = c;
    }
    dist[1] = 0;
    for(int i=0; i<=N; ++i){
        for(auto it : EG){
            if(dist[it.u]!=INF && dist[it.u] + G[it.u][it.v] < dist[it.v]){
                dist[it.v] = dist[it.u] + G[it.u][it.v];
            }
        }
    }
    for(auto it : EG){
        if(dist[it.u] == INF) continue;
        if(dist[it.u] + G[it.u][it.v] < dist[it.v]){
            cout << "-1" << '\n';
            return 0;
        }
    }
    for(int i=2; i<=N; ++i){
        if(dist[i] == INF) cout << "-1" << '\n';
        else cout << dist[i] << '\n';
    }
}