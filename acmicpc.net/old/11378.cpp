#include <bits/stdc++.h>
using namespace std;
const int MN = 1001;
vector<int> G[MN*2+3];
int c[MN*2+3][MN*2+3], f[MN*2+3][MN*2+3];
int S=MN*2, T=MN*2+1, A=MN*2+2;
int MaxFlow(int src, int snk){
	int ret=0;
	while(1){
		queue<int> q; q.push(src);
		vector<int> p(MN*2+3, -1); p[src]=src;
		while(!q.empty() && p[snk]==-1){
			int cur = q.front(); q.pop();
			for(auto nxt:G[cur]){
				if(c[cur][nxt]-f[cur][nxt]>0 && p[nxt]==-1){
					p[nxt]=cur;
					q.push(nxt);
				}
			}
		}
		if(p[snk]==-1) break;
		int flow = 1987654321;
		for(int i=snk; i!=src; i=p[i]){
			flow = min(flow, c[p[i]][i] - f[p[i]][i]);
		}
		for(int i=snk; i!=src; i=p[i]){
			f[p[i]][i] += flow;
			f[i][p[i]] -= flow;
		}
		ret+=flow;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M, K; cin>>N>>M>>K;
	G[S].push_back(A);
	G[A].push_back(S);
	c[S][A]=K;
	for(int i=1; i<=N; ++i){
		int a; cin>>a;
		G[S].push_back(i);
		G[i].push_back(S);
		c[S][i]=1;
		G[A].push_back(i);
		G[i].push_back(A);
		c[A][i]=K;
		for(int j=0; j<a; ++j){
			int w; cin>>w; w+=MN;
			G[i].push_back(w);
			G[w].push_back(i);
			c[i][w]=1;
		}
	}
	for(int i=1; i<=M; ++i){
		G[i+MN].push_back(T);
		G[T].push_back(i+MN);
		c[i+MN][T]=1;
	}
	cout << MaxFlow(S, T) << '\n';
}