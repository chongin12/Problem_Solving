#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const ll INF=1e18;
vector<pll> G[1001];
ll visited[1001];
ll dist[1001][1001];
ll N, P, K;
struct Edge {
	ll v, w, d;
	Edge(ll v, ll w, ll d):v(v),w(w),d(d){}	
};
struct comp {
	bool operator()(Edge a, Edge b){
		return a.w>b.w;	
	}	
};
ll bfs(ll u){
	queue<pll> q;
	q.push({u, 0});
	visited[u]=1;
	while(!q.empty()){
		pll cur = q.front(); q.pop();
		if(cur.first==N){
			return cur.second;
		}
		for(auto nxt:G[cur.first]){
			if(visited[nxt.first]) continue;
			visited[nxt.first]=1;
			q.push({nxt.first, cur.second+1});
		}
	}
	return INF;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N>>P>>K;
	for(ll i=0; i<P; ++i){
		ll u, v, w; cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	ll r = bfs(1);
//	cout << "bfs value : " << r << '\n';
	if(r==INF){
		cout << "-1\n";
		return 0;
	}
	if(r<=K) {
		cout << "0\n";
		return 0;
	}
	//dijkstra
	for(ll i=1; i<=N; ++i){
		for(ll j=0; j<=K; ++j){
			dist[i][j]=-INF;
		}
	}
	for(int i=0; i<=K; ++i) dist[1][i]=0;
	priority_queue<Edge, vector<Edge>, comp> pq;
	pq.push(Edge(1, dist[1][0], 0));
	while(!pq.empty()){
		Edge cur = pq.top(); pq.pop();
		if(dist[cur.v][cur.d] < cur.w) continue;
//		cout << "cur.v : " << cur.v << ", cur.w : " << cur.w << ", cur.d : " << cur.d << '\n';
		for(auto nxt:G[cur.v]){
			ll nxtv=nxt.first;
			ll w=max(dist[cur.v][cur.d], nxt.second);
			if(dist[nxtv][cur.d]==-INF){
				dist[nxtv][cur.d]=w;
				if(nxtv!=N) pq.push(Edge(nxtv, w, cur.d));
			}
			else if(dist[nxtv][cur.d] > w) {
				dist[nxtv][cur.d]=w;
				if(nxtv!=N) pq.push(Edge(nxtv, w, cur.d));
			}
			if(cur.d < K){
				w=dist[cur.v][cur.d];
				if(dist[nxtv][cur.d+1]==-INF){
					dist[nxtv][cur.d+1]=w;
					if(nxtv!=N) pq.push(Edge(nxtv, w, cur.d+1));
				}
				else if(dist[nxtv][cur.d+1] > w) {
					dist[nxtv][cur.d+1]=w;
					if(nxtv!=N) pq.push(Edge(nxtv, w, cur.d+1));
				}
			}
		}
	}
	ll ret = INF;
	for(int i=0; i<=K; ++i){
//		cout << "dist["<<N<<"]["<<i<<"]="<<dist[N][i]<<'\n';
		if(dist[N][i]==-INF) continue;
		ret = min(ret, dist[N][i]);
	}
	cout << ret << '\n';
}
