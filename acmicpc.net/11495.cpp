#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
const int MN=50;
const int MNMN=2500;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int arr[MN][MN];
vector<int> G[MNMN+2];
int c[MNMN+2][MNMN+2], f[MNMN+2][MNMN+2], p[MNMN+2];
void init(){
	memset(c,0,sizeof(c));
	memset(f,0,sizeof(f));
	for(int i=0; i<MNMN+2; ++i) G[i].clear();
}
int maxFlow(int src, int snk){
	int ret=0;
	while(1){
		fill(p,p+MNMN+2,-1); p[src]=src;
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
		int flow=INF;
		for(int i=snk; i!=src; i=p[i]){
			flow=min(flow,c[p[i]][i]-f[p[i]][i]);
		}
		for(int i=snk; i!=src; i=p[i]){
			f[p[i]][i]+=flow;
			f[i][p[i]]-=flow;
		}
		ret+=flow;
	}
	for(auto nxt:G[src]){
		ret+=c[src][nxt]-f[src][nxt];
	}
	for(auto prv:G[snk]){
		ret+=c[prv][snk]-f[prv][snk];
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin>>T;
	while(T--){
		init();
		int n, m; cin>>n>>m;
		int src=MNMN, snk=MNMN+1;
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cin>>arr[i][j];
			}
		}
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				int cur=i*m+j;
				if((i+j)%2){
					G[src].push_back(cur);
					G[cur].push_back(src);
					c[src][cur]=arr[i][j];
					for(int k=0; k<4; ++k){
						int ni=i+dx[k];
						int nj=j+dy[k];
						int nxt=ni*m+nj;
						if(ni>=0 && ni<n && nj>=0 && nj<m){
							G[cur].push_back(nxt);
							G[nxt].push_back(cur);
							c[cur][nxt]=INF;
						}
					}
				}
				else{
					G[cur].push_back(snk);
					G[snk].push_back(cur);
					c[cur][snk]=arr[i][j];
				}
			}
		}
		cout << maxFlow(src,snk) << '\n';
	}
}