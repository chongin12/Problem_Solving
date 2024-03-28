#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF=1987654321;
vector<pii> G[10001];
int visited[10001];
int dist[10001];
int U,V;
struct Edge {
    int v,w;
    Edge(int v, int w):v(v),w(w) {}
};
struct comp {
    bool operator()(Edge a, Edge b){
        return a.w<b.w;
    }
};
void init(){
    for(int i=0; i<10001; ++i){
        dist[i]=INF;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int N,M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int A,B,C; cin>>A>>B>>C;
        G[A].push_back({B,C});
        G[B].push_back({A,C});
    }
    cin>>U>>V;
    priority_queue<Edge, vector<Edge>, comp> pq;
    pq.emplace(U,INF);
    dist[U]=INF;
    while(!pq.empty()){
        Edge cur = pq.top(); pq.pop();
        if(dist[cur.v] > cur.w) continue;
        for(auto it:G[cur.v]){
            int m=min(dist[cur.v],it.second);
            if(dist[it.first]==INF){
                dist[it.first]=m;
                pq.emplace(it.first, m);
            }
            if(dist[it.first]<m){
                dist[it.first] = m;
                pq.emplace(it.first, m);
            }
        }
    }
    cout << dist[V] << '\n';
}