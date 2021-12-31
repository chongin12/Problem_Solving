#include <bits/stdc++.h>
using namespace std;
const double INF=987654321.0;
double dp[201][201];
double G[201][201];
int visit[201][201];
int main(){
	int N,M; cin>>N>>M;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			dp[i][j]=INF;
		}
		dp[i][i]=0;
	}
	for(int i=0; i<M; ++i){
		int s,e;
		double l; cin>>s>>e>>l;
		s--; e--;
		if(s!=e){
			if(dp[s][e]==INF){
				dp[s][e]=l;
				dp[e][s]=l;
			}
			else{
				dp[s][e]=min(dp[s][e],l);
				dp[e][s]=min(dp[e][s],l);
			}
		}
		G[s][e]=max(G[s][e],l);
		G[e][s]=max(G[e][s],l);
	}
	for(int k=0; k<N; ++k){
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	// for(int i=0; i<N; ++i){
	// 	for(int j=0; j<N; ++j){
	// 		cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
	// 	}
	// }
	double m=INF;
	for(int k=0; k<N; ++k){
		//k가 시작점일 때
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				visit[i][j]=0;
			}
		}
		double time=0;
		for(int i=0; i<N; ++i){
			//k에서 i로 가는 경로들을 탐색한다.
			time=max(time,dp[k][i]);
			for(int j=0; j<N; ++j){
				if(G[i][j] && !visit[i][j]){
					//i->j 경로를 다 태우는 시간과 max를 비교.
					visit[i][j]=1;
					visit[j][i]=1;
					time=max(time,min(dp[k][i],dp[k][j])+abs(dp[k][i]-dp[k][j])+(G[i][j]-(abs(dp[k][i]-dp[k][j])))/2.0);
				}
			}
		}
		m=min(m,time);
	}
	cout.precision(1);
	cout << fixed;
	cout << m << '\n';
}