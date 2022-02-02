#include <bits/stdc++.h>
using namespace std;
const int MN=1000;
const int INF=987654321;
vector<int> G[MN*2+3];
int c[MN*2+3][MN*2+3], f[MN*2+3][MN*2+3], p[MN*2+3];
int maxFlow(int src, int snk){
	int ret=0;
	while(1){
		fill(p, p+MN*2+3, -1); p[src]=src;
		queue<int> q; q.push(src);
		while(!q.empty() && p[snk]==-1){
			int cur=q.front(); q.pop();
			for(auto nxt:G[cur]){
				if(c[cur][nxt]-f[cur][nxt]>0 && p[nxt]==-1){
					p[nxt]=cur;
					q.push(nxt);
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
		}
		ret+=flow;
	}
	return ret;
}
int main(){
	int N, M, K; cin>>N>>M>>K;
	int src=MN*2, bridge=MN*2+1, snk=MN*2+2;
	G[src].push_back(bridge);
	G[bridge].push_back(src);
	c[src][bridge]=K;
	for(int i=0; i<N; ++i){
		G[src].push_back(i);
		G[i].push_back(src);
		c[src][i]=1;
		G[bridge].push_back(i);
		G[i].push_back(bridge);
		c[bridge][i]=1;
		int a; cin>>a;
		for(int j=0; j<a; ++j){
			int w; cin>>w; w--;
			G[i].push_back(w+MN);
			G[w+MN].push_back(i);
			c[i][w+MN]=1;
		}
	}
	for(int i=0; i<M; ++i){
		G[i+MN].push_back(snk);
		G[snk].push_back(i+MN);
		c[i+MN][snk]=1;
	}
	cout << maxFlow(src, snk) << '\n';
}