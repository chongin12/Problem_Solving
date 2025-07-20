#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[31];
ll dp2[31]; // 좌우대칭인 것의 개수
int main(){
    ll N; cin>>N;
    dp[2]=3;
    dp[1]=1;
    for(ll i=3; i<=N; ++i){
        dp[i]=dp[i-1]+dp[i-2]*2;
    }
    dp2[0]=1;
    dp2[1]=1;
    dp2[2]=3;
    dp2[3]=1;
    dp2[4]=5;
    for(ll i=4; i<=N; ++i){
        dp2[i]=dp2[i-2]+dp2[i-4]*2;
    }
    cout << (dp[N]-dp2[N])/2+dp2[N] << '\n';
}