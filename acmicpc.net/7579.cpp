#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll a[101];
ll c[101];
ll dp[101][10101];
ll sum;
// dp[i][j] = i번째 앱까지 활성화 될 때, j비용을 사용하면 나오는 최소 메모리
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1; i<=n; ++i){
		cin>>c[i];
		if(c[i]!=0) dp[i][0]=dp[i-1][0]+a[i];
		else dp[i][0]=dp[i-1][0];
		for(int j=1; j<10101; ++j){
			if(j<c[i]) dp[i][j]=min(dp[i-1][j]+a[i], dp[i][j-1]);
			else dp[i][j]=min(dp[i-1][j]+a[i], dp[i-1][j-c[i]]);
			//cout << "i : " << i << ", j : "<<j<<", dp=>"<<dp[i][j]<<'\n';
		}
	}
	for(int j=0; j<10101; ++j){
		if(dp[n][j]<=sum-m){
			cout << j << '\n';
			break;
		}
	}
}