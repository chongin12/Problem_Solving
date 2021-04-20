#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321;
using namespace std;
struct edge {
    int v, w;
    edge(int v, int w) : v(v), w(w) {}
};
vector<edge> G[1001];
vector<int> route[1001]; // A -> i일때 경로 
int dist[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i=0; i<m; ++i){
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back(edge(v,w));
    }
    int A, B; cin >> A >> B;
    for(int i=0; i<1001; ++i) dist[i]=INF;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii> > pq;// first : dist, second : target node
    route[A].push_back(A);
    pq.push({0, A});
    dist[A] = 0;

    while(!pq.empty()) {
        pii top = pq.top(); pq.pop();
        int curDist = top.first;
        int cur = top.second;

        if(dist[cur] < curDist) continue;
        //A -> cur로 가는 경로 확정.
        for(edge nxtEdge : G[cur]) {
            int nxt = nxtEdge.v;
            if(dist[nxt] > dist[cur] + nxtEdge.w){
                dist[nxt] = dist[cur] + nxtEdge.w;
                //A -> nxt로 가는 경로 미리 정해두기
                route[nxt] = route[cur];
                route[nxt].push_back(nxt);
                pq.push({dist[nxt], nxt});
            }
        }
    }
    cout << dist[B] << '\n';
    cout << route[B].size() << '\n';
    for(int it:route[B]) {
        cout << it << " ";
    }
    cout << '\n';
}