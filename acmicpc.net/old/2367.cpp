#include <bits/stdc++.h>
using namespace std;
const int MN=200;
const int INF=987654321;
vector<int> G[MN*2+2];
int c[MN*2+2][MN*2+2], f[MN*2+2][MN*2+2], p[MN*2+2];
int maxFlow(int src, int snk){
	int ret=0;
	while(1){
		fill(p, p+MN*2+2, -1); p[src]=src;
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
	ios::sync_with_stdio(0); cin.tie(0);
	int N,K,D; cin>>N>>K>>D;
	int src=MN*2, snk=MN*2+1;
	for(int i=0; i<D; ++i){
		int a; cin>>a;
		G[i+MN].push_back(snk);
		G[snk].push_back(i+MN);
		c[i+MN][snk]=a;
	}
	for(int i=0; i<N; ++i){
		G[src].push_back(i);
		G[i].push_back(src);
		c[src][i]=K;
		int a; cin>>a;
		for(int j=0; j<a; ++j){
			int b; cin>>b; b--;
			G[i].push_back(b+MN);
			G[b+MN].push_back(i);
			c[i][b+MN]=1;
		}
	}
	cout << maxFlow(src, snk) << '\n';
}