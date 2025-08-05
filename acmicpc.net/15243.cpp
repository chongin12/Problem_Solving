#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[1001];
int main(){
    ll W; cin>>W;
    dp[1]=0;
    dp[2]=3;
    for(ll i=4; i<=W; i+=2){
        dp[i]+=dp[i-2]*3;
        for(ll j=4; i-j>0; j+=2){
            dp[i]+=dp[i-j]*2;
            dp[i]%=1000000007;
        }
        dp[i]+=2;
        dp[i]%=1000000007;
    }
    cout << dp[W]%1000000007 << '\n';
}