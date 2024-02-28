#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int dp[1600][10];
int res=1;
int main(){
    int N; cin>>N;
    dp[1][1] = 1;
    dp[1][5] = 1;
    if(N==1){
        cout << "0\n";
        return 0;
    }
    for(int i=2; i<N; ++i){
        // 1을 넣었을 때
        dp[i][1] += dp[i-1][9];
        dp[i][1]%=MOD;
        for(int j=2; j<=9; ++j){
            dp[i][j] += dp[i-1][j-1];
            dp[i][j]%=MOD;
        }

        // 5를 넣었을 때
        for(int j=1; j<=5; ++j){
            dp[i][j]+=dp[i-1][4+j];
            dp[i][j]%=MOD;
        }
        for(int j=6; j<=9; ++j){
            dp[i][j]+=dp[i-1][j-5];
            dp[i][j]%=MOD;
        }
        res=(dp[i][1]+dp[i][4]+dp[i][7])%MOD;
    }
    cout << res << '\n';
}