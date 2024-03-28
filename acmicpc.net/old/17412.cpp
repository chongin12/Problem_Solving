#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int MN=401;
vector<int> G[MN];
int c[MN][MN], f[MN][MN];
int MaxFlow(int src, int snk){
	int ret=0;
	while(1){
		queue<int> q; q.push(src);
		vector<int> p(MN, -1); p[src]=src;
		while(!q.empty() && p[snk]==-1){
			int cur = q.front(); q.pop();
			for(auto nxt:G[cur]){
				if(c[cur][nxt] - f[cur][nxt] > 0 && p[nxt]==-1){
					p[nxt]=cur;
					q.push(nxt);
				}
			}
		}
		if(p[snk]==-1) break;
		int flow = 1987654321;
		for(int i=snk; i!=src; i=p[i]){
			flow = min(flow, c[p[i]][i]-f[p[i]][i]);
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
	int N, P; cin>>N>>P;
	for(int i=0; i<P; ++i){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		c[u][v]=1;
	}
	cout << MaxFlow(1,2) << '\n';
}
