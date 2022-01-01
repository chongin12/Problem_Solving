#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int MN=1e9;
const int INF=987654321;
struct edge{
	int v,w;
	edge(int v, int w) : v(v), w(w) {}
};
vector<edge> G[MN];
int dist[MN];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M; cin>>N>>M;
	for(int i=1; i<=M; ++i){
		int u,v; cin>>u>>v;
		u--; v--;
		G[u].push_back(edge(v,i));
		G[v].push_back(edge(u,i));
	}
	for(int i=0; i<N; ++i){
		dist[i]=INF;
	}
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({0,0});
	dist[0]=0;
	while(!pq.empty()){
		pii top = pq.top(); pq.pop();
		
	}
}