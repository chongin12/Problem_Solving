#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MN=1e9+9;
ll dp[100001][4];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    dp[1][1]=1;
    dp[2][2]=1;
    dp[3][1]=1;
    dp[3][2]=1;
    dp[3][3]=1;
    for(int i=4; i<=100000; ++i){
        dp[i][1]=(dp[i-1][2]+dp[i-1][3])%MN;
        dp[i][2]=(dp[i-2][1]+dp[i-2][3])%MN;
        dp[i][3]=(dp[i-3][1]+dp[i-3][2])%MN;
    }
    while(T--){
        int n; cin>>n;
        cout << (dp[n][1]+dp[n][2]+dp[n][3])%MN << '\n';
    }
}