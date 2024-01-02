#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000;
int dp[1001][2][3]; // dp[i][j][k] = i일까지 지각 j번, 결석 연속 k번
int main(){
    int N; cin>>N;
    dp[1][0][0]=1;
    dp[1][1][0]=1;
    dp[1][0][1]=1;
    for(int i=2; i<=N; ++i){
        // 출석
        dp[i][0][0]+=dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2];
        dp[i][1][0]+=dp[i-1][1][0]+dp[i-1][1][1]+dp[i-1][1][2];
        // 지각
        dp[i][1][0]+=dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2];
        // 결석
        dp[i][0][1]+=dp[i-1][0][0];
        dp[i][0][2]+=dp[i-1][0][1];
        dp[i][1][1]+=dp[i-1][1][0];
        dp[i][1][2]+=dp[i-1][1][1];
        dp[i][0][0]%=MOD;
        dp[i][0][1]%=MOD;
        dp[i][0][2]%=MOD;
        dp[i][1][0]%=MOD;
        dp[i][1][1]%=MOD;
        dp[i][1][2]%=MOD;
    }
    int sum=0;
    sum+=dp[N][0][0]+dp[N][0][1]+dp[N][0][2]+dp[N][1][0]+dp[N][1][1]+dp[N][1][2];
    cout << sum%MOD << '\n';
}