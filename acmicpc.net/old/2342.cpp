#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
// cache[i][j] = i->j로 갈 때 드는 힘
int cache[5][5] = {
	{0,2,2,2,2},
	{INF,1,3,4,3},
	{INF,3,1,3,4},
	{INF,4,3,1,3},
	{INF,3,4,3,1},
}; 
int dp[2][5][5];
//dp[k][i][j] = k%2번째 지시에서 왼발이 i, 오른발이 j에 있을 때 최소 힘
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a;
	for(int i=0; i<2; ++i){
		for(int j=0; j<5; ++j){
			for(int k=0; k<5; ++k){
				dp[i][j][k]=INF;
			}
		}
	}
	dp[0][0][0]=0;
	for(int k=1; ; ++k){
		for(int i=0; i<5; ++i){
			for(int j=0; j<5; ++j){
				dp[k%2][i][j]=INF;
			}
		}
		cin>>a;
		if(a==0) {
			int res=INF;
			for(int i=0; i<5; ++i){
				for(int j=0; j<5; ++j){
					res=min(res,dp[(k-1)%2][i][j]);
				}
			}
			cout << res << '\n';
			break;
		}
		//1. 왼발을 이동
		for(int i=0; i<5; ++i){ 
			for(int j=0; j<5; ++j){
				dp[k%2][a][i]=min(dp[k%2][a][i],dp[(k-1)%2][j][i]+cache[j][a]);
			}
		}
		for(int i=0; i<5; ++i){ 
			for(int j=0; j<5; ++j){
				dp[k%2][i][a]=min(dp[k%2][i][a],dp[(k-1)%2][i][j]+cache[j][a]);
			}
		}
	}
}