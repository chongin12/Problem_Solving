/*
dp[i][k][m] = 길이가 i이고, k로 끝나고, 비트마스크 m의 수가 등장하는 계단수 개수를 1e9로 나눈 나머지
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll dp[101][10][1024];
const int D=1e9;
int main(){
	int n;cin>>n;
	for(int i=1; i<=9; ++i) {
		dp[1][i][1<<i]=1;
	}
	for(int k=2; k<=n; ++k){
		for(int i=0; i<=9; ++i){
			for(int j=1; j<1024; ++j){
				if(i>0 && dp[k-1][i-1][j]!=0) dp[k][i][j|(1<<i)]+=dp[k-1][i-1][j];
				if(i<9 && dp[k-1][i+1][j]!=0) dp[k][i][j|(1<<i)]+=dp[k-1][i+1][j];
				dp[k][i][j|(1<<i)]%=D;
				//if(dp[k][i][j|(1<<i)]!=0) cout << dp[k][i][j|(1<<i)] << " <- k : " <<k<<", i : "<<i<<", j|(1<<i) : "<<(j|(1<<i))<<'\n';
			}
		}
	}
	ll res=0;
	// ll rrr=0;
	// for(int i=1; i<=n; ++i){
	// 	for(int j=0; j<=9; ++j){
	// 		rrr+=dp[i][j][1023];
	// 	}
	// }
	for(int i=0; i<=9; ++i){
		res+=dp[n][i][1023];
		res%=D;
	}
	cout << res << '\n';
	//cout << rrr << '\n';
}