#include <bits/stdc++.h>
using namespace std;
const int INF=987564321;
int N,M;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<string> arr;
vector<int> G[202002]; // 정점을 모두 두개로 쪼갠다.
map<pair<int,int>, int> C;
map<pair<int,int>, int> F;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N>>M;
	for(int i=0; i<N; ++i){
		string str; cin>>str; arr.push_back(str);
	}
	int src=-1, srci=-1, srcj=-1, snk=-1, snki=-1, snkj=-1;
	int cnt=-2;
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			cnt+=2;
			if(arr[i][j]=='K'){
				src=cnt+1;
				srci=i;
				srcj=j;
			}
			if(arr[i][j]=='H'){
				snk=cnt;
				snki=i;
				snkj=j;
			}
			if(arr[i][j]=='#'){
				continue;
			}
			C[{cnt,cnt+1}]=1;
			C[{cnt+1,cnt}]=0;
			G[cnt].push_back(cnt+1);
			G[cnt+1].push_back(cnt);
			for(int k=0; k<2; ++k){
				int nxti=i+dx[k];
				int nxtj=j+dy[k];
				if(nxti>=0 && nxti<N && nxtj>=0 && nxtj<M){
					if(arr[nxti][nxtj]=='#') continue;
					int nxtCnt=(nxti*M+nxtj)*2;
					// cout << cnt << " <-> " << nxtCnt << '\n';
					//cnt+1과 nxtCnt를 연결
					//nxtCnt+1과 cnt를 연결
					G[cnt+1].push_back(nxtCnt);
					G[nxtCnt].push_back(cnt+1);

					G[cnt].push_back(nxtCnt+1);
					G[nxtCnt+1].push_back(cnt);

					C[{cnt+1,nxtCnt}]=INF;
					C[{nxtCnt,cnt+1}]=0;
					
					C[{cnt,nxtCnt+1}]=0;
					C[{nxtCnt+1,cnt}]=INF;
				}
			}
		}
	}
	if((srci==snki && srcj==snkj) || abs(srci-snki)+abs(srcj-snkj)==1 || src==-1 || snk==-1){
		cout << "-1\n";
		return 0;
	}
	int ret=0;
	while(1){
		queue<int> q; q.push(src);
		vector<int> p(20002,-1); p[src]=src;
		while(!q.empty() && p[snk]==-1){
			int cur=q.front(); q.pop();
			for(int i=0; i<G[cur].size(); ++i){
				int nxt=G[cur][i];
				if(C[{cur,nxt}]-F[{cur,nxt}]>0 && p[nxt]==-1){
					q.push(nxt);
					p[nxt]=cur;
				}
			}
		}
		if(p[snk]==-1) break;
		int flow=INF;
		for(int i=snk; i!=src; i=p[i]){
			flow = min(flow, C[{p[i],i}]-F[{p[i],i}]);
		}
		for(int i=snk; i!=src; i=p[i]){
			F[{p[i],i}]+=flow;
			F[{i,p[i]}]-=flow;
		}
		ret+=flow;
	}
	cout << ret << '\n';
}