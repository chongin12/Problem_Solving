#include <bits/stdc++.h>
using namespace std;
struct shark{
	int a,b,c;
	shark(int a, int b, int c):a(a),b(b),c(c){}
};
const int MN=50;
const int INF=987654321;
vector<int> G[MN*2+2];
int c[MN*2+2][MN*2+2], f[MN*2+2][MN*2+2], p[MN*2+2];
int maxFlow(int src, int snk){
	int ret=0;
	while(1){
		fill(p, p+MN*2+2, -1);
		p[src]=src;
		queue<int> q; q.push(src);
		while(!q.empty() && p[snk]==-1){
			int cur=q.front(); q.pop();
			for(auto nxt:G[cur]){
				if(c[cur][nxt]-f[cur][nxt]>0 && p[nxt]==-1){
					q.push(nxt);
					p[nxt]=cur;
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
	int N; cin>>N;
	vector<shark> v;
	int src=MN*2, snk=MN*2+1;
	for(int i=0; i<N; ++i){
		int a,b,c; cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	// 잡아먹는 정점 : i, 잡아먹히는 정점 : i+MN
	for(int i=0; i<v.size(); ++i){
		G[src].push_back(i);
		G[i].push_back(src);
		c[src][i]=2;
		G[i+MN].push_back(snk);
		G[snk].push_back(i+MN);
		c[i+MN][snk]=1;
		for(int j=0; j<v.size(); ++j){
			if(i==j) continue;
			if(v[i].a==v[j].a && v[i].b==v[j].b && v[i].c==v[j].c && i>j){
				continue;
			}
			if(v[i].a>=v[j].a && v[i].b>=v[j].b && v[i].c>=v[j].c){
				G[i].push_back(j+MN);
				G[j+MN].push_back(i);
				c[i][j+MN]=1;
			}
		}
	}
	cout << N-maxFlow(src,snk) << '\n';
}