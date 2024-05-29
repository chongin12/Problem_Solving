#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[101][101][2];
// 0 : 오른쪽으로 가다가 위쪽으로
// 1 : 위쪽으로 가다가 오른쪽으로
const ll MOD = 100000;
int main(){
    ll w, h; cin>>w>>h;
    for(ll i=1; i<=w; ++i){
        dp[i][1][0]=1;
    }
    for(ll j=1; j<=h; ++j){
        dp[1][j][1]=1;
    }
    for(ll i=2; i<=w; ++i){
        for(ll j=2; j<=h; ++j){
            for(ll k=j-2; k>=1; --k){
                dp[i][j][1]+=dp[i][k][0];
                dp[i][j][1]%=MOD;
            }
            for(ll k=i-2; k>=1; --k){
                dp[i][j][0]+=dp[k][j][1];
                dp[i][j][0]%=MOD;
            }
        }
    }
    cout << (dp[w][h][0]+dp[w][h][1]+dp[w-1][h][1]+dp[w][h-1][0])%MOD << '\n';
}