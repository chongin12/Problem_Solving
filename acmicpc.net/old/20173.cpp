#include <bits/stdc++.h>
using namespace std;
bool dp[1000101][2][2];
int v[1000101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>v[i];
    }
    if(v[1]==0){
        dp[2][0][0]=true;
        dp[2][1][1]=true;
    }
    if(v[1]==1){
        dp[2][0][1]=true;
        dp[2][1][0]=true;
    }
    for(int i=3; i<=n; ++i){
        for(int j=0; j<2; ++j){
            for(int k=0; k<2; ++k){
                if(!dp[i-1][j][k]) continue;
                if(v[i-1]==0){
                    dp[i][j][k]=true;
                }
                if(v[i-1]==1){
                    if(j!=k){
                        dp[i][0][0]=true;
                        dp[i][1][1]=true;
                    }
                    else{
                        dp[i][0][1]=true;
                        dp[i][1][0]=true;
                    }
                }
                if(v[i-1]==2 && j!=k){
                    dp[i][k][j]=true;
                }
                // cout << "dp["<<i<<"]["<<j<<"]["<<k<<"]="<<dp[i][j][k]<<'\n';
            }
        }
    }
    bool flag=false;
    if(v[n]==0){
        if(dp[n][0][0] || dp[n][1][1]) flag=true;
    }
    else if(v[n]==1){
        if(dp[n][0][1] || dp[n][1][0]) flag=true;
    }
    cout << (flag ? "YES" : "NO") << '\n';
}