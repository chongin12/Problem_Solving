#include <bits/stdc++.h>
using namespace std;
string arr[751];
int prf[4][751][751];
int dp[2][751][751]; // [0][i][j] : < , [1][i][j] : >
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int R,C; cin>>R>>C;
	for(int i=0;i<R;++i){
		cin>>arr[i];
	}
	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j){
			if(arr[i][j]=='1'){
				if(i>0 && j>0) prf[0][i][j]=prf[0][i-1][j-1]+1;
				else prf[0][i][j]=1;
			}
		}
	}
	for(int i=0; i<R; ++i){
		for(int j=C-1; j>=0; --j){
			if(arr[i][j]=='1'){
				if(i>0 && j<C-1) prf[1][i][j]=prf[1][i-1][j+1]+1;
				else prf[1][i][j]=1;
			}
		}
	}
	for(int i=R-1; i>=0; --i){
		for(int j=0; j<C; ++j){
			if(arr[i][j]=='1'){
				if(i<R-1 && j>0) prf[2][i][j]=prf[2][i+1][j-1]+1;
				else prf[2][i][j]=1;
			}
		}
	}
	for(int i=R-1; i>=0; --i){
		for(int j=C-1; j>=0; --j){
			if(arr[i][j]=='1'){
				if(i<R-1 && j<C-1) prf[3][i][j]=prf[3][i+1][j+1]+1;
				else prf[3][i][j]=1;
			}
		}
	}
	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j){
			dp[0][i][j] = min(prf[1][i][j],prf[3][i][j]);
			dp[1][i][j] = min(prf[0][i][j],prf[2][i][j]);
		}
	}
	// for(int i=0; i<R; ++i){
	// 	for(int j=0; j<C; ++j){
	// 		cout << dp[0][i][j]<<" ";
	// 	}
	// 	cout << '\n';
	// }
	// cout << "-----------------\n";
	// for(int i=0; i<R; ++i){
	// 	for(int j=0; j<C; ++j){
	// 		cout << dp[1][i][j]<<" ";
	// 	}
	// 	cout << '\n';
	// }
	int res=0;
	for(int i=0; i<R; ++i){
		for(int j=0; j<C; ++j){
			for(int k=dp[0][i][j]; k>res; --k){
				int t=(k-1)*2;
				if(j+t>=C) continue;
				if(dp[1][i][j+t]>=k) res=k;
			}
		}
	}
	cout << res << '\n';
}
/*
근데 대각선 안해도 될꺼같은데
해당 값 기준으로 dp1은 >방향, dp2는 <방향 연속 합들을 구하는게 나을듯?
*/