#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin>>T;
	while(T--){
		int N,W;cin>>N>>W;
		int arr[2][10101]={0,};
		for(int i=0; i<2; ++i){
			for(int j=0; j<N; ++j){
				cin>>arr[i][j];
			}
			arr[i][N]=arr[i][0];
		}
		int dp[10101][10];
		/*
		dp[i][k] : i번째 칸을 k방법으로 묶었을 때 최소개수
		k방법으로 묶지 못한다면? INF
		1 3
		2 4
		라고 했을 때
		k=0 : 가로
			(1,3),(2,4)
		k=1 : 가로
			(1,3),(2),(4)
		k=2 : 가로
			(1),(3),(2,4)
		k=3 : 세로
			(1,2)
		k=4 : 세로
			(1),(2)
		*/
		dp[0][0]=INF;
		dp[0][1]=INF;
		dp[0][2]=INF;
		dp[0][3]=2;
		if(arr[0][0]+arr[1][0]>W) dp[0][4]=INF;
		else dp[0][4]=1;
		if(arr[0][0]+arr[0][1]>W || arr[1][0]+arr[1][1]>W) dp[1][0]=INF;
		else dp[1][0]=2;
		if(arr[0][0]+arr[0][1]>W) dp[1][1]=INF;
		else dp[1][1]=3;
		if(arr[1][0]+arr[1][1]>W) dp[1][2]=INF;
		else dp[1][2]=3;
		dp[1][3]=min(dp[0][3],dp[0][4])+2;
		if(arr[0][1]+arr[1][1]>W) dp[1][4]=INF;
		else dp[1][4]=min(dp[0][3],dp[0][4])+1;
		for(int i=2; i<N; ++i){ // 1. 1~N-1
			dp[i][0]=INF;
			dp[i][1]=INF;
			dp[i][2]=INF;
			if(arr[0][i-1]+arr[0][i]<=W){
				if(arr[1][i-1]+arr[1][i]<=W){
					for(int j=0; j<5; ++j){
						dp[i][0]=min(dp[i][0],dp[i-2][j]+2);
					}
				}
				else{
					for(int j=0; j<5; ++j){
						dp[i][1]=min(dp[i][1],dp[i-2][j]+3);
					}
					if(arr[1][i-2]+arr[1][i-1]<=W){
						dp[i][1]=min(dp[i][1],dp[i-2][1]+2);
						dp[i][1]=min(dp[i][1],dp[i-1][3]+1);
					}
				}
			}
			else{
				if(arr[1][i-1]+arr[1][i]<=W){
					for(int j=0; j<5; ++j){
						dp[i][2]=min(dp[i][2],dp[i-2][j]+3);
					}
					if(arr[0][i-2]+arr[0][i-1]<=W){
						dp[i][2]=min(dp[i][2],dp[i-2][1]+2);
						dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
					}
				}
			}

			dp[i][3]=INF;
			dp[i][4]=INF;
			for(int j=0; j<5; ++j){
				dp[i][3]=min(dp[i][3],dp[i-1][j]+2);
			}
			if(arr[0][i]+arr[1][i]<=W){
				for(int j=0; j<5; ++j){
					dp[i][4]=min(dp[i][4],dp[i-1][j]+1);
				}
			}
		}
		//2. 2~N
		int dpp[10101][10];
		dpp[1][0]=INF;
		dpp[1][1]=INF;
		dpp[1][2]=INF;
		dpp[1][3]=2;
		if(arr[0][1]+arr[1][1]>W) dpp[1][4]=INF;
		else dpp[1][4]=1;
		if(arr[0][1]+arr[0][2]>W || arr[1][1]+arr[1][2]>W) dpp[2][0]=INF;
		else dpp[2][0]=2;
		if(arr[0][1]+arr[0][2]>W) dpp[2][1]=INF;
		else dpp[2][1]=3;
		if(arr[1][1]+arr[1][2]>W) dpp[2][2]=INF;
		else dpp[2][2]=3;
		dpp[2][3]=min(dpp[1][3],dpp[1][4])+2;
		if(arr[0][2]+arr[1][2]>W) dpp[2][4]=INF;
		else dpp[2][4]=min(dpp[1][3],dpp[1][4])+1;
		for(int i=3; i<=N; ++i){
			dpp[i][0]=INF;
			dpp[i][1]=INF;
			dpp[i][2]=INF;
			if(arr[0][i-1]+arr[0][i]<=W){
				if(arr[1][i-1]+arr[1][i]<=W){
					for(int j=0; j<5; ++j){
						dpp[i][0]=min(dpp[i][0],dpp[i-2][j]+2);
					}
					//TODO
					if(arr[1][i-2]+arr[1][i-1]<=W){
						dpp[i][1]=min(dpp[i][1],dpp[i-2][1]+2);
						dpp[i][1]=min(dpp[i][1],dpp[i-1][3]+1);
					}
					//TODO
				}
				else{
					for(int j=0; j<5; ++j){
						dpp[i][1]=min(dpp[i][1],dpp[i-2][j]+3);
					}
				}
			}
			else{
				if(arr[1][i-1]+arr[1][i]<=W){
					for(int j=0; j<5; ++j){
						dpp[i][2]=min(dpp[i][2],dpp[i-2][j]+3);
					}
					//TODO
					if(arr[0][i-2]+arr[0][i-1]<=W){
						dpp[i][2]=min(dpp[i][2],dpp[i-2][1]+2);
						dpp[i][2]=min(dpp[i][2],dpp[i-1][3]+1);
					}
					//TODO
				}
			}

			dpp[i][3]=INF;
			dpp[i][4]=INF;
			for(int j=0; j<5; ++j){
				dpp[i][3]=min(dpp[i][3],dpp[i-1][j]+2);
			}
			if(arr[0][i]+arr[1][i]<=W){
				for(int j=0; j<5; ++j){
					dpp[i][4]=min(dpp[i][4],dpp[i-1][j]+1);
				}
			}
		}
		int mm=INF;
		for(int j=0; j<5; ++j){
			mm=min(mm,dp[N-1][j]);
			mm=min(mm,dpp[N][j]);
		}
		cout << mm << '\n';
		/*
		for(int i=0; i<N; ++i){
			for(int j=0; j<5; ++j){
				cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
			}
		}
		
		cout << "------\n";
		for(int i=1; i<=N; ++i){
			for(int j=0; j<5; ++j){
				cout << "dpp["<<i<<"]["<<j<<"]="<<dpp[i][j]<<'\n';
			}
		}
		*/
	}
}