#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MN=500;
vector<int> G[MN*2+2];
int c[MN*2+2][MN*2+2], f[MN*2+2][MN*2+2], p[MN*2+2];
vector<pair<int,int> > v1;
vector<pair<int,int> > v2;
void init(){
	v1.clear();
	v2.clear();
	for(int i=0; i<MN*2+2; ++i){
		G[i].clear();
		for(int j=0; j<MN*2+2; ++j){
			c[i][j]=0;
			f[i][j]=0;
		}
	}
}
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
	int T; cin>>T;
	while(T--){
		int C,D,V; cin>>C>>D>>V;
		init();
		int src=MN*2, snk=MN*2+1;
		for(int i=0; i<V; ++i){
			string s1,s2; cin>>s1>>s2;
			int r1=0,r2=0;
			for(int j=1; j<s1.size(); ++j){
				r1=10*r1+s1[j]-'0';
			}
			for(int j=1; j<s2.size(); ++j){
				r2=10*r2+s2[j]-'0';
			}
			if(s1[0]=='C') v1.push_back({r1,r2});
			else v2.push_back({r1,r2});
		}
		for(int i=0; i<v1.size(); ++i){
			G[src].push_back(i);
			G[i].push_back(src);
			c[src][i]=1;
			for(int j=0; j<v2.size(); ++j){
				if(v1[i].first==v2[j].second || v1[i].second==v2[j].first){
					G[i].push_back(j+MN);
					G[j+MN].push_back(i);
					c[i][j+MN]=1;
				}
			}
		}
		for(int i=0; i<v2.size(); ++i){
			G[i+MN].push_back(snk);
			G[snk].push_back(i+MN);
			c[i+MN][snk]=1;
		}
		int res=maxFlow(src,snk);
		cout << V-res << '\n';
	}
}