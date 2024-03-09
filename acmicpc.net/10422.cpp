#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 1e9+7;
ll dp[5001]; // 길이가 i이고 묶음의 개수가 1인 개수
ll f(int l){ // 길이가 l일 때 모든 경우의 수
    if(l%2) return 0;
    if(dp[l]) return dp[l];
    ll ret=0;
    for(int i=0; i<l; i+=2){
        ret+=f(i)*f(l-i-2);
        ret%=MOD;
    }
    return dp[l]=ret%MOD;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    dp[0]=1;
    dp[2]=1;

    ll T; cin>>T;
    while(T--){
        ll a; cin>>a;
        cout << f(a) << '\n';
    }
}