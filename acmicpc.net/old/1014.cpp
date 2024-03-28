#include <bits/stdc++.h>
using namespace std;
int dp[10][1024]; //  dp[i][j] : i번째 행에서 j로 마스킹 되어있을 때, i~N-1 최대학생수
vector<string> v;
// vector<string> temp;
int N,M;
void init(){
	for(int i=0; i<10; ++i){
		for(int j=0; j<1024; ++j){
			dp[i][j]=-1;
		}
	}
	v.clear();
	// temp.clear();
}
int f(int x, int mask, int cnt){ // x행을 mask했을 때 x~N-1 최대 학생 수, cnt는 mask의 1의 개수
	if(dp[x][mask]!=-1) return dp[x][mask];
	if(x==N-1) return cnt;
	for(int k=0; k<(1<<M); ++k){ // 다음 행(x+1)을 k 로 마스킹
		bool pass=true;
		int t=0;
		for(int i=0; i<M; ++i){
			if(k&(1<<i)){
				if(v[x+1][i]=='x') pass=false;
				else if(i!=0 && mask&(1<<(i-1))) pass=false;
				else if(i!=0 && k&(1<<(i-1))) pass=false;
				else if(i!=M-1 && mask&(1<<(i+1))) pass=false;
				else if(i!=M-1 && k&(1<<(i+1))) pass=false;
				t++;
			}
			if(!pass) break;
		}
		if(pass) dp[x][mask]=max(dp[x][mask], cnt+f(x+1,k, t));
	}
	return dp[x][mask];
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int C;cin>>C;
	while(C--){
		cin>>N>>M;
		init();
		for(int i=0; i<N; ++i){
			string str; cin>>str;
			v.push_back(str);
		}
		int res=0;
		for(int k=0; k<(1<<M); ++k){
			bool pass=true;
			int cnt=0;
			for(int i=0; i<M; ++i){
				if(k&(1<<i)){
					if(v[0][i]=='x') pass=false;
					else if(i!=0 && k&(1<<(i-1))) pass=false;
					else if(i!=N-1 && k&(1<<(i+1))) pass=false;
					cnt++;
				}
				if(!pass) break;
			}
			if(pass) {
				dp[0][k]=f(0, k, cnt);
				res=max(res,dp[0][k]);
			}
		}
		cout << res << '\n';
	}
}