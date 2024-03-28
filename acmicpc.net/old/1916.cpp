#include <iostream>
#include <queue>
using namespace std;

const int MN = 2e4;
const int INF = 1e9;

struct edge {
   int v, w; 
   edge(int v, int w) : v(v), w(w) {}
};

vector<edge> G[MN];
int dist[MN];
int main(){
	int N, M; cin >> N >> M;
	for(int i=0; i<M; ++i){
		int u, v, w;   cin >> u >> v >> w;
		u--, v--;
		G[u].push_back(edge(v, w));
	}
	int K,KK; cin >> K >> KK;
	K--; KK--;
	for(int i=0; i<N; ++i){
		dist[i] = INF;
	}
	using P = pair<int, int>;
	priority_queue<P, vector<P>, greater<P> > pq; 
	pq.push(make_pair(0, K));
	dist[K] = 0;

	while(!pq.empty()) {
		P top = pq.top(); pq.pop();
		int cur_dist = top.first;
		int cur = top.second;

		if(dist[cur] < cur_dist) continue;
		for(edge nxt_edge : G[cur]) {
			int nxt = nxt_edge.v;
			if(dist[nxt] > dist[cur] + nxt_edge.w) {
				dist[nxt] = dist[cur] + nxt_edge.w;
				pq.push(make_pair(dist[nxt], nxt));
			}
		}
	}
	cout << dist[KK] << '\n';
}