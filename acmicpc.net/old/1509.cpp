/*
dp[i][j]=i~j 구간 문자열이 팰린드롬인지?
dpp[i]=i까지 해서 최소 문자열 분할 개수
*/
#include <bits/stdc++.h>
using namespace std;
bool dp[2501][2501];
int dpp[2501];
string arr;
int main(){
	cin>>arr;
	int len=arr.size();
	arr=" "+arr;
	dp[0][0]=true;
	for(int j=1; j<=len; ++j){
		for(int i=1; i<=j; ++i){
			if(i==j) dp[i][j]=true;
			else if(i+1==j && arr[i]==arr[j]) dp[i][j]=true;
			else if(dp[i+1][j-1] && arr[i]==arr[j]) dp[i][j]=true;
			else dp[i][j]=false;
			// cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
		}
	}
	dpp[0]=0;
	dpp[1]=1;
	for(int i=2; i<=len; ++i){
		dpp[i]=dpp[i-1]+1;
		for(int j=1; j<=i; ++j){
			if(dp[j][i]){
				dpp[i]=min(dpp[i],dpp[j-1]+1);
			}
		}
	}
	cout << dpp[len] << '\n';
}