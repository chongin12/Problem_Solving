#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll P=1000000;
ll dp[2][101][101];// d : 0이면 증가, 1이면 감소
ll f(int d, int left, int right){
	if(dp[d][left][right]!=-1) return dp[d][left][right];
	if(left==0 && right==0) return dp[d][left][right]=1;
	ll sum=0;
	if(d==0){ // left에 있는 걸 선택해야 함.
		for(int i=0; i<left; ++i){
			sum+=f(1,i,left+right-i-1);
			sum%=P;
		}
	}
	else{
		for(int i=0; i<right; ++i){
			sum+=f(0,left+i,right-i-1);
			sum%=P;
		}
	}
	return dp[d][left][right]=sum%P;
}
int main(){
	ll N ;cin>>N;
	if(N==1) {
		cout << "1\n";
		return 0;
	}
	for(int i=0; i<2; ++i){
		for(int j=0; j<101; ++j){
			for(int k=0; k<101; ++k){
				dp[i][j][k]=-1;
			}
		}
	}
	ll res=0;
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			if(i==j) continue;
			// cout << "i : " << i << ", j : " << j << " -> ";
			if(i<j){
				// cout << "d : "<<0<<", left : "<<j-2 <<", right : " << N-j << '\n';
				res+=f(0,j-2,N-j);
				// cout << "+="<<f(0,j-2,N-j) << '\n';
			}
			else{
				// cout << "d : "<<1<<", left : "<<j-1 <<", right : " << N-j-1 << '\n';
				res+=f(1,j-1,N-j-1);
				// cout << "+="<<f(0,j-2,N-j) << '\n';
			}
			res%=P;
		}
	}
	cout << res << '\n';
}