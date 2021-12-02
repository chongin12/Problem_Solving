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
		for(int i=2; i<N; ++i){
			
		}
	}
}