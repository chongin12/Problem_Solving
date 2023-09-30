#include <bits/stdc++.h>
using namespace std;
int dp[21][10001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        vector<int> v(N+1);
        for(int i=1; i<=N; ++i){
            cin>>v[i];
        }
        int M; cin>>M;
        dp[0][0]=1;
        for(int i=1; i<=N; ++i){
            for(int j=0; j<v[i]; ++j){
                dp[i][j]=dp[i-1][j];
            }
            for(int j=v[i]; j<=M; ++j){
                dp[i][j]=dp[i-1][j];
                for(int k=1; k*v[i]<=j; k++){
                    dp[i][j]+=dp[i-1][j-k*v[i]];
                }
                // dp[i][j]=dp[i-1][j] + dp[i-1][j-v[i]]+1;
                // dp[i][j]=dp[i-1][j]+dp[i-1][j-v[i]]+1;
                
            }
        }
        cout << dp[N][M] << '\n';
    }
}