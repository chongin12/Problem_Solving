#include <bits/stdc++.h>
using namespace std;
int dp[301][18];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1; i<=17; ++i) dp[0][i]=1;
    for(int i=1; i<=300; ++i){
        dp[i][1]=1;
        for(int j=2; j<=17; ++j){
            dp[i][j]=dp[i][j-1];
            if(i>=j*j) {
                for(int k=1; j*j*k<=i; ++k){
                    dp[i][j]+=dp[i-j*j*k][j-1];
                }
            }
        }
    }
    while(1){
        int N; cin>>N;
        if(N==0) break;
        cout << dp[N][17] << '\n';
    }
}