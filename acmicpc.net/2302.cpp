#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[41]; // 좌석이 i개 연속으로 붙어있을 때 자리바꾸는 경우의 수
/*
dp[0]=0;
dp[1]=1;
dp[2]=2;
dp[3]=3;

*/
int main(){
    ll N, M; cin>>N>>M;
    ll res=1;
    ll prev=0;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(ll i=3; i<=40; ++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
    for(ll i=0; i<M; ++i){
        ll a; cin>>a;
        res*=dp[a-prev-1];
        prev=a;
    }
    res*=dp[N-prev];
    cout << res << '\n';
}