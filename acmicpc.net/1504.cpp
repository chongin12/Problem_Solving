#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
const int MN = 1000 + 1;
const ll INF = 987654321;
struct edge {
    int v;
    ll w;
    edge(int v, ll w) : v(v) , w(w) {}
};

vector<edge> G[MN];
priority_queue<P, vector<P>, greater<P> > pq;
ll dist[MN];
priority_queue<P, vector<P>, greater<P> > pq2;
ll dist2[MN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    while(M--){
        int u, v; 
        ll w; cin >> u >> v >> w;
        G[u].push_back(edge(v, w));
        G[v].push_back(edge(u, w));
    }
    int K1, K2; cin >> K1 >> K2;
    for(int i=1; i<MN; ++i){
        dist[i]=INF;
        dist2[i] = INF;
    }
    dist[K1] = 0;
    dist2[K2] = 0;
    pq.push({0, K1});
    pq2.push({0, K2});
    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        ll curDist = p.first;
        int cur = p.second;

        if(dist[cur] < curDist) continue;
        for(edge nextEdge:G[cur]){
            int nextVertex = nextEdge.v;
            ll nextEdgeWeight = nextEdge.w;
            if(dist[nextVertex] > dist[cur] + nextEdgeWeight){
                dist[nextVertex] = dist[cur] + nextEdgeWeight;
                pq.push({dist[nextVertex], nextVertex});
            }
        }
    }
    while(!pq2.empty()){
        P p = pq2.top(); pq2.pop();
        ll curDist = p.first;
        int cur = p.second;

        if(dist2[cur] < curDist) continue;
        for(edge nextEdge:G[cur]){
            int nextVertex = nextEdge.v;
            ll nextEdgeWeight = nextEdge.w;
            if(dist2[nextVertex] > dist2[cur] + nextEdgeWeight){
                dist2[nextVertex] = dist2[cur] + nextEdgeWeight;
                pq2.push({dist2[nextVertex], nextVertex});
            }
        }
    }
    ll start_K1 = dist[1]; //K1 -> start
    ll end_K1 = dist[N]; //K1 -> end
    ll start_K2 = dist2[1]; // K2 -> start
    ll end_K2 = dist2[N]; // K2 -> end
    ll K1_K2 = dist[K2];
    if(K1_K2+start_K1+end_K2 >= INF || K1_K2+start_K2+end_K1 >= INF){
        cout << "-1" << '\n';
    }
    else if(start_K1 + end_K2 < start_K2 + end_K1) {
        cout << K1_K2+start_K1+end_K2 << '\n';
    }
    else {
        cout << K1_K2+start_K2+end_K1 << '\n';
    }
}