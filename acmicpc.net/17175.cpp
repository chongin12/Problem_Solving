#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[51];
int main(){
    ll N; cin>>N;
    dp[0]=1;
    dp[1]=1;
    dp[2]=3;
    for(ll i=3; i<=N; ++i){
        dp[i]=(dp[i-1]+dp[i-2]+1)%1000000007;
    }
    cout << dp[N] << '\n';
}