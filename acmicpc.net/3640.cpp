#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MN=1000;
vector<int> G[MN*2+1];
int cost[MN*2+1][MN*2+1];
int c[MN*2+1][MN*2+1], f[MN*2+1][MN*2+1], p[MN*2+1], dist[MN*2+1], isInQueue[MN*2+1];
void init(){
	for(int i=0; i<MN*2+1; ++i){
		G[i].clear();
		for(int j=0; j<MN*2+1; ++j){
			c[i][j]=0;
			f[i][j]=0;
			cost[i][j]=0;
		}
	}
}
int maxFlow(int src, int snk){
	int ret=0;
	while(1){
		fill(isInQueue, isInQueue+MN*2+1, 0); isInQueue[src]=1;
		fill(p, p+MN*2+1, -1); p[src]=src;
		fill(dist, dist+MN*2+1, INF); dist[src]=0;
		queue<int> q; q.push(src);
		while(!q.empty()){
			int cur=q.front(); q.pop();
			isInQueue[cur]=0;
			for(auto nxt:G[cur]){
				if(c[cur][nxt]-f[cur][nxt]>0 && dist[nxt]>dist[cur]+cost[cur][nxt]){
					dist[nxt]=dist[cur]+cost[cur][nxt];
					p[nxt]=cur;
					if(!isInQueue[nxt]){
						isInQueue[nxt]=1;
						q.push(nxt);
					}
				}
			}
		}
		if(p[snk]==-1) break;
		int flow=INF;
		for(int i=snk; i!=src; i=p[i]){
			flow=min(flow, c[p[i]][i]-f[p[i]][i]);
		}
		for(int i=snk; i!=src; i=p[i]){
			f[p[i]][i]+=flow;
			f[i][p[i]]-=flow;
			ret+=flow*cost[p[i]][i];
			// cout << "p[i] : " << p[i] << ", i : " << i << ", flow : " << flow << ", cost[p[i]][i] : " <<cost[p[i]][i] << '\n';
		}
		// cout << "*** ret : " << ret << '\n';
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M;
	int src=MN*2, snk;
	while(cin>>N>>M){
		init();
		snk=N-1;
		for(int i=0; i<M; ++i){
			//모든 정점을 받는노드(i), 주는노드(i+MN)으로 분리하여 경로가 겹치지 않게 해준다.
			int u,v,w; cin>>u>>v>>w; u--; v--;
			G[u+MN].push_back(v);
			G[v].push_back(u+MN);
			c[u+MN][v]=1;
			cost[u+MN][v]=w;
			cost[v][u+MN]=-w;
		}
		for(int i=0; i<N; ++i){
			G[i].push_back(i+MN);
			G[i+MN].push_back(i);
			c[i][i+MN]=1;
		}
		G[src].push_back(0+MN);
		G[0+MN].push_back(src);
		c[src][0+MN]=2;
		cout << maxFlow(src, snk) << '\n';
	}
}