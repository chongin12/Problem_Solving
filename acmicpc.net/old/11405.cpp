#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MN=100;
vector<int> G[MN*2+2];
int cost[MN*2+2][MN*2+2];
int c[MN*2+2][MN*2+2], f[MN*2+2][MN*2+2], p[MN*2+2];
int isInQueue[MN*2+2], dist[MN*2+2];
int maxFlow(int src, int snk){
	int ret=0;
	while(1){
		fill(isInQueue, isInQueue+MN*2+2, 0); isInQueue[src]=1;
		fill(dist, dist+MN*2+2, INF); dist[src]=0;
		fill(p, p+MN*2+2, -1); p[src]=src;
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
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M; cin>>N>>M;
	int src=MN*2, snk=MN*2+1;
	for(int i=0; i<N; ++i){
		int a; cin>>a;
		G[src].push_back(i);
		G[i].push_back(src);
		c[src][i]=a;
	}
	for(int i=0; i<M; ++i){
		int a; cin>>a;
		G[i+MN].push_back(snk);
		G[snk].push_back(i+MN);
		c[i+MN][snk]=a;
	}
	for(int i=0; i<M; ++i){
		for(int j=0; j<N; ++j){
			int a; cin>>a;
			G[j].push_back(i+MN);
			G[i+MN].push_back(j);
			c[j][i+MN]=INF;
			cost[j][i+MN]=a;
			cost[i+MN][j]=-a;
		}
	}
	cout << maxFlow(src, snk) << '\n';
}