#include <bits/stdc++.h>
using namespace std;
int dp[1500100];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int res=0;
    for(int i=1; i<=N; ++i){
        int t, p; cin>>t>>p;
        dp[i]=max(dp[i], dp[i-1]);
        dp[i+t]=max(dp[i+t],dp[i]+p);
        res=max(res,dp[i]);
        // cout << "dp["<<i<<"]="<<dp[i]<<'\n';
    }
    // cout << "dp["<<N+1<<"]="<<dp[N+1]<<'\n';
    cout << max(res,dp[N+1]) << '\n';
}