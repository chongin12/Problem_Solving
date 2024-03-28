#include <bits/stdc++.h>
using namespace std;
int dp[1002][31];
int main(){
    int T,W; cin>>T>>W;
    int a; cin>>a;
    dp[1][a-1]=1;
    int res=1;
    for(int i=2; i<=T; ++i){
        cin>>a;
        if(a==1) dp[i][0]=dp[i-1][0]+1;
        res=max(res,dp[i][0]);
        for(int j=1; j<=W; ++j){
            if(j%2){
                if(a==2){
                    dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
                }
            }
            else{
                if(a==1){
                    dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
                }
            }
            res=max(res,dp[i][j]);
        }
    }
    cout << res << '\n';
}