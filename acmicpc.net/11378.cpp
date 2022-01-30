#include <bits/stdc++.h>
using namespace std;
const int MN=2003;
const int INF=987654321;
vector<int> G[MN];
int c[MN][MN], f[MN][MN], p[MN];
int N,M,K,res,score[1001];
int maxFlow(int src, int snk){
	int ret=0;
	while(1){
		fill(p,p+MN,-1);
		queue<int> q;
		q.push(src);
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
		int fl=INF;
		for(int i=snk; i!=src; i=p[i]){
			fl=min(fl,c[p[i]][i]-f[p[i]][i]);
		}
		for(int i=snk; i!=src; i=p[i]){
			f[p[i]][i]+=fl;
			f[i][p[i]]-=fl;
		}
	}
	for(auto it:G[src]){
		ret+=f[src][it];
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M>>K;
	for(int i=1; i<=N; ++i){
		int a; cin>>a;
		for(int j=0; j<a; ++j){
			int temp; cin>>temp; temp+=1000;
			G[i].push_back(temp);
			G[temp].push_back(i);
			c[i][temp]=1;
		}
	}
	int src=0, snk=MN-2, mid=MN-1;
	// src : 0
	// 직원 : 1~1000
	// 일 : 1001 ~ 2000
	// snk : 2001
	// 중간노드 : 2002
	G[src].push_back(mid);
	G[mid].push_back(src);
	c[src][mid]=K;
	for(int i=1; i<=N; ++i){
		G[src].push_back(i);
		G[i].push_back(src);
		c[src][i]=1;

		G[mid].push_back(i);
		G[i].push_back(mid);
		c[mid][i]=K;
	}
	for(int i=1; i<=M; ++i){
		G[i+1000].push_back(snk);
		G[snk].push_back(i+1000);
		c[i+1000][snk]=1;
	}
	cout << maxFlow(src,snk) << '\n';
}