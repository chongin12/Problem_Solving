#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[51]; // dp[i] : 레벨 i에서의 패티 개수
ll dp2[51]; // dp2[i] : 레벨 i에서의 레이어 개수
ll f(ll X, ll phase){
    if(X<0) return 0;
    if(X && phase==0) return 1;
    if(X==dp2[phase-1]+2){
        return dp[phase-1]+1;
    }
    if(X>dp2[phase-1]+2){
        return dp[phase-1]+1+f(X-dp2[phase-1]-2, phase-1);
    }
    return f(X-1, phase-1);
}
int main(){
    ll N, X; cin>>N>>X;
    dp[0]=1;
    dp2[0]=1;
    for(ll i=1; i<51; ++i){
        dp[i]=dp[i-1]*2+1;
        dp2[i]=dp2[i-1]*2+3;
    }
    cout << f(X, N) << '\n';
}