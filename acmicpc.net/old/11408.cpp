#include <bits/stdc++.h>
using namespace std;
const int MN=400; // 직원 0~399, 일 400~799, src 800, snk 801
const int INF=987654321;
vector<int> G[MN*2+2];
int cost[MN*2+2][MN*2+2];
int c[MN*2+2][MN*2+2], f[MN*2+2][MN*2+2], p[MN*2+2], dist[MN*2+2], isInQueue[MN*2+2];
pair<int,int> maxFlow(int src, int snk){ // {개수,유량*비용}
	pair<int,int> ret={0,0};
	while(1){
		fill(dist, dist+MN*2+2, INF); dist[src]=0;
		fill(isInQueue, isInQueue+MN*2+2, 0); isInQueue[src]=1;
		fill(p, p+MN*2+2, -1); p[src]=src;
		queue<int> q; q.push(src);
		while(!q.empty()){
			int cur=q.front(); q.pop();
			isInQueue[cur]=0;
			for(auto nxt:G[cur]){
				if(c[cur][nxt]-f[cur][nxt]>0 && dist[cur]+cost[cur][nxt]<dist[nxt]){
					dist[nxt]=dist[cur]+cost[cur][nxt];
					p[nxt]=cur;
					if(!isInQueue[nxt]){
						q.push(nxt);
						isInQueue[nxt]=1;
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
			ret.second+=flow*cost[p[i]][i];
			f[p[i]][i]+=flow;
			f[i][p[i]]-=flow;
		}
		ret.first+=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M; cin>>N>>M;
	int src=MN*2, snk=MN*2+1;
	for(int i=0; i<N; ++i){
		int a; cin>>a;
		for(int j=0; j<a; ++j){
			int b,w; cin>>b>>w; b--;
			G[i].push_back(b+MN);
			G[b+MN].push_back(i);
			cost[i][b+MN]=w;
			cost[b+MN][i]=-w;
			c[i][b+MN]=1;
		}
	}
	for(int i=0; i<N; ++i){
		G[src].push_back(i);
		G[i].push_back(src);
		c[src][i]=1;
	}
	for(int i=0; i<M; ++i){
		G[i+MN].push_back(snk);
		G[snk].push_back(i+MN);
		c[i+MN][snk]=1;
	}
	pair<int,int> res=maxFlow(src, snk);
	cout << res.first << '\n' << res.second << '\n';
}