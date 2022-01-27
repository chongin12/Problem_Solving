#include <bits/stdc++.h>
using namespace std;
int dp[10001][101];
int f(int n, int m){
	if(dp[n][m]!=-1) return dp[n][m];
	if(m==0) return 0;
	if(n%m==0) return n/m;
	dp[n][m]=n*m;
	if(n > 3*m) {
		return dp[n][m]=1+f(n-m,m);
	}
	for(int i=1; i<=n/2; ++i){
		dp[n][m]=min(dp[n][m], f(n-i,m)+f(i,m));
	}
	for(int j=1; j<=m/2; ++j){
		dp[n][m]=min(dp[n][m], f(n,j)+f(n,m-j));
	}
	return dp[n][m];
}
int main(){
	int n,m; cin>>n>>m;
	memset(dp, -1, sizeof(dp));
	cout << f(n,m) << '\n';
}