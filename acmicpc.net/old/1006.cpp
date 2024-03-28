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
		}
		int area0=arr[0][0];
		int area1=arr[1][0];
		int mm=N*2;
		for(int phase=0; phase<4; ++phase){
			arr[0][0]=W;
			arr[1][0]=W;
			arr[0][N]=W;
			arr[1][N]=W;
			if(phase==0){
				arr[0][0]=area0;
				arr[1][0]=area1;
			}
			else if(phase==1){
				arr[0][N]=area0;
				arr[1][0]=area1;
			}
			else if(phase==2){
				arr[0][0]=area0;
				arr[1][N]=area1;
			}
			else{
				arr[0][N]=area0;
				arr[1][N]=area1;
			}
			int dp[10101][10]={0,};
			
			dp[0][0]=INF;
			dp[0][1]=INF;
			dp[0][2]=INF;
			dp[0][3]=2;
			dp[0][4]=INF;
			if(arr[0][0]+arr[1][0]<=W) dp[0][4]=1;

			dp[1][0]=INF;
			dp[1][1]=INF;
			dp[1][2]=INF;
			if(arr[0][0]+arr[0][1]<=W && arr[1][0]+arr[1][1]<=W) dp[1][0]=2;
			if(arr[0][0]+arr[0][1]<=W) dp[1][1]=3;
			if(arr[1][0]+arr[1][1]<=W) dp[1][2]=3;
			dp[1][3]=min(dp[0][3],dp[0][4])+2;
			dp[1][4]=INF;
			if(arr[0][1]+arr[1][1]<=W) dp[1][4]=min(dp[0][3],dp[0][4])+1;
			for(int i=2; i<=N; ++i){
				dp[i][0]=INF;
				dp[i][1]=INF;
				dp[i][2]=INF;
				if(arr[0][i-1]+arr[0][i]<=W){
					if(arr[1][i-1]+arr[1][i]<=W){
						for(int j=0; j<5; ++j){
							dp[i][0]=min(dp[i][0],dp[i-2][j]+2);
							dp[i][1]=min(dp[i][1],dp[i-2][j]+3);
							dp[i][2]=min(dp[i][2],dp[i-2][j]+3);
						}
						if(arr[1][i-2]+arr[1][i-1]<=W){
							dp[i][1]=min(dp[i][1],dp[i-2][1]+2);
							dp[i][1]=min(dp[i][1],dp[i-2][3]+2);
							dp[i][1]=min(dp[i][1],dp[i-1][3]+1);
							dp[i][1]=min(dp[i][1],dp[i-1][2]+1);
						}
						if(arr[0][i-2]+arr[0][i-1]<=W){
							dp[i][2]=min(dp[i][2],dp[i-2][2]+2);
							dp[i][2]=min(dp[i][2],dp[i-2][3]+2);
							dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
							dp[i][2]=min(dp[i][2],dp[i-1][1]+1);
						}
					}
					else{
						for(int j=0; j<5; ++j){
							dp[i][1]=min(dp[i][1],dp[i-2][j]+3);
						}
						if(arr[1][i-2]+arr[1][i-1]<=W){
							dp[i][1]=min(dp[i][1],dp[i-2][1]+2);
							dp[i][1]=min(dp[i][1],dp[i-2][3]+2);
							dp[i][1]=min(dp[i][1],dp[i-1][3]+1);
							dp[i][1]=min(dp[i][1],dp[i-1][2]+1);
						}
					}
				}
				else{
					if(arr[1][i-1]+arr[1][i]<=W){
						for(int j=0; j<5; ++j){
							dp[i][2]=min(dp[i][2],dp[i-2][j]+3);
						}
						if(arr[0][i-2]+arr[0][i-1]<=W){
							dp[i][2]=min(dp[i][2],dp[i-2][2]+2);
							dp[i][2]=min(dp[i][2],dp[i-2][3]+2);
							dp[i][2]=min(dp[i][2],dp[i-1][3]+1);
							dp[i][2]=min(dp[i][2],dp[i-1][1]+1);
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
			for(int j=0; j<5; ++j){
				mm=min(mm,dp[N][j]-2);
			}
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