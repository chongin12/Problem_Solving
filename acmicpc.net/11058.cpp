#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[110];
int main(){
    int N; cin>>N;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=4;
    dp[5]=5;
    for(ll i=3; i<=N; ++i){
        dp[i]=max(dp[i], i);
        for(ll j=i+3; j<=N; ++j){
            dp[j]=max(dp[j], dp[i]*(j-(i+1)));
        }
    }
    cout << dp[N] << '\n';
}