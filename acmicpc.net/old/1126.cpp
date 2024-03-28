#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=600001;
ll dp[51][MN];
//dp[i][j] : i까지 고려했을 때 두 타워의 높이 차
ll dp2[51][MN];
//dp[i][j]일 때 둘 중 작은 높이
int main(){
	int N; cin>>N;
	ll res=-1;
	for(int i=1; i<=N; ++i){
		ll a; cin>>a;
		if(i==1){
			dp[1][0]=1;
			dp[1][a]=1;
			dp2[1][a]=0;
		}
		else{
			for(int j=0; j<MN; ++j){
				if(dp[i-1][j]){
					dp[i][j]=max(dp[i][j], dp[i-1][j]);
					dp2[i][j]=max(dp2[i][j], dp2[i-1][j]);
					// cout << "dp["<<i-1<<"]["<<j<<"]=1\n";
					// cout << "dp2["<<i-1<<"]["<<j<<"]="<<dp2[i-1][j]<<"\n";
					if(j+a<MN){
						dp[i][j+a]=1;
						dp2[i][j+a]=max(dp2[i][j+a],dp2[i-1][j]);
					}
					if(j-a>=0){
						dp[i][j-a]=1;
						dp2[i][j-a]=max(dp2[i][j-a], dp2[i-1][j]+a);
						if(j-a==0) {
							// cout << "i가 "<<i<<"일 때 0이 됨.\n";
							// cout << "dp2["<<i<<"]["<<j-a<<"]="<<dp2[i][j-a]<<'\n';
							res=max(res,dp2[i][j-a]);
						}
					}
					else{
						dp[i][a-j]=1;
						dp2[i][a-j]=max(dp2[i][a-j], dp2[i-1][j]+j);
					}
				}
			}
		}
	}
	if(res<=0) cout << "-1\n";
	else cout << res << '\n';
}