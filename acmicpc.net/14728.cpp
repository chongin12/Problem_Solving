#include <bits/stdc++.h>
using namespace std;
int dp[101][10001];
int main(){
    int N, T; cin>>N>>T;
    for(int i=1; i<=N; ++i){
        int a,b; cin>>a>>b;
        for(int j=0; j<a; ++j){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=a; j<=T; ++j){
            dp[i][j]=max(dp[i-1][j], dp[i-1][j-a]+b);
        }
    }
    cout << dp[N][T] << '\n';
}