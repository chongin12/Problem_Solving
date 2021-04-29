#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
struct edge {
    int u, v;
    edge(int u, int v) : u(u), v(v) {}
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int TC; cin >> TC;
    while(TC--){
        bool FLAG = false;
        int G[501][501];
        vector<edge> edgeGroup;
        for(int i=0; i<501; ++i){
            for(int j=0; j<501; ++j){
                G[i][j] = INF;
            }
        }
        int N, M, W; cin >> N >> M >> W;
        for(int i=0; i<M; ++i){
            int S, E, T; cin >> S >> E >> T;
            if(G[S][E] == INF) edgeGroup.push_back(edge(S, E));
            if(G[E][S] == INF) edgeGroup.push_back(edge(E, S));
            if(G[S][E] > T) G[S][E] = T;
            if(G[E][S] > T) G[E][S] = T;
        }
        for(int i=0; i<W; ++i){
            int S, E, T; cin >> S >> E >> T;
            T=-T;
            if(G[S][E] == INF) edgeGroup.push_back(edge(S, E));
            if(G[S][E] > T) G[S][E] = T;
        }
        int visit[501] = {};
        for(int k=1; k<=N; ++k){
            if(visit[k]) continue;
            int dist[501];
            for(int i=0; i<501; ++i) dist[i] = INF;
            dist[k] = 0;
            for(auto it : edgeGroup) {
                if(dist[it.u] + G[it.u][it.v] < dist[it.v]){
                    dist[it.v] = dist[it.u] + G[it.u][it.v];
                }
            }
            dist[k] = INF;
            for(int i=1; i<=N; ++i){
                for(auto it : edgeGroup) {
                    if(dist[it.u] + G[it.u][it.v] < dist[it.v]){
                        dist[it.v] = dist[it.u] + G[it.u][it.v];
                    }
                }
            }
            if(dist[k]<0) FLAG = true;
            for(auto it : edgeGroup) {
                if(FLAG) break;
                if(dist[it.u] + G[it.u][it.v] < dist[it.v]){
                    FLAG = true;
                }
            }
            if(FLAG) break;
            for(int i=1; i<=N; ++i){
                if(dist[i]!=INF) visit[i] = 1;
            }
        }
        if(FLAG) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}