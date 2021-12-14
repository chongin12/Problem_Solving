#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
int dp[1001][3][3]; //dp[i][k1][k2] : i번째까지 칠했을 때 k1으로 칠하는 방법, 처음엔 k2로 칠함.
int main(){
	int N; cin>>N;
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			dp[0][i][j]=INF;
		}
	}
	cin >> dp[0][0][0] >> dp[0][1][1] >> dp[0][2][2];
	for(int i=1; i<N; ++i){
		int a,b,c;cin>>a>>b>>c;
		for(int j=0; j<3; ++j){
			dp[i][0][j]=min(dp[i-1][1][j],dp[i-1][2][j])+a;
			dp[i][1][j]=min(dp[i-1][0][j],dp[i-1][2][j])+b;
			dp[i][2][j]=min(dp[i-1][0][j],dp[i-1][1][j])+c;
		}
	}
	int res=INF;
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			if(i==j) continue;
			res=min(res,dp[N-1][i][j]);
		}
	}
	cout << res << '\n';
}