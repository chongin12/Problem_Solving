#include <bits/stdc++.h>
using namespace std;
int n;
int dp[16][65536]; // dp[i][mask]=i~0까지 mask들을 방문하는 최소비용
int arr[16][16];
const int INF=987654321;
int dfs(int x, int mask){
	if(mask==(1<<n)-1) {
		if(arr[x][0]==0) return INF;
		return arr[x][0];
	}
	if(dp[x][mask]) return dp[x][mask];
	dp[x][mask]=INF;
	for(int i=0; i<n; ++i){
		if(mask&(1<<i) || arr[x][i]==0) continue;
		dp[x][mask]=min(dp[x][mask],dfs(i,mask|(1<<i))+arr[x][i]);
	}
	return dp[x][mask];
}
int main(){
	cin>>n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin>>arr[i][j];
		}
	}
	cout << dfs(0,1)<<'\n';
}