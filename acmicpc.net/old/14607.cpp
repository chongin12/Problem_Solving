#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[1000001];
ll f(ll x){
    if(x<=1000000) return dp[x];
    return (x/2)*(x-x/2)+f(x/2)+f(x-x/2);
}
int main(){
    ll N; cin>>N;
    dp[2]=1;
    for(ll i=3; i<=1000000; ++i){
        dp[i]=(i/2)*(i-i/2)+dp[i/2]+dp[i-i/2];
    }
    cout << f(N) << '\n';
}