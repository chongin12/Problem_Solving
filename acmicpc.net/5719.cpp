#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF=987654321;
const int MN=511;
int N,M,S,E;
int visit[MN];
int dist[MN];
struct edge{
	int v,w;
	edge(int v, int w):v(v),w(w){}
};
vector<edge> G[MN];
vector<int> G2[MN]; // 새로운 경로를 넣어준다.
void dijkstra1(){
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({0,S});
	dist[S]=0;
	while(!pq.empty()){
		pii top=pq.top();pq.pop();
		int cur_dist=top.first;
		int cur=top.second;

		if(dist[cur] < cur_dist) continue;
		for(edge nxt_edge:G[cur]){
			if(nxt_edge.w==INF) continue;
			int nxt=nxt_edge.v;
			if(dist[nxt] > dist[cur] + nxt_edge.w){
				dist[nxt]=dist[cur]+nxt_edge.w;
				pq.push({dist[nxt],nxt});
				G2[nxt].clear();
				G2[nxt].push_back(cur);
			}
			else if(dist[cur] + nxt_edge.w == dist[nxt]){
				G2[nxt].push_back(cur);
			}
		}
	}
}
void bfs(){
	queue<int> q;
	q.push(E);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(visit[cur]) continue;
		visit[cur]=1;
		for(int i=0; i<G2[cur].size(); ++i){
			int nxt=G2[cur][i];
			for(int j=0; j<G[nxt].size(); ++j){
				if(G[nxt][j].v==cur){
					G[nxt][j].w=INF;
				}
			}
			q.push(nxt);
		}
	}
}
void init() {
	for(int i=0; i<MN; ++i){
		G[i].clear();
		G2[i].clear();
		visit[i]=0;
		dist[i]=INF;
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(1){
		init();
		cin>>N>>M;
		if(N==0 && M==0) break;
		cin>>S>>E;
		for(int i=0; i<M; ++i){
			int u,v,w; cin>>u>>v>>w;
			G[u].push_back(edge(v,w));
		}
		dijkstra1();
		bfs();
		for(int i=0; i<MN; ++i) dist[i]=INF;
		dijkstra1();
		if(dist[E]==INF) cout << -1 << '\n';
		else cout << dist[E] << '\n';
	}
}