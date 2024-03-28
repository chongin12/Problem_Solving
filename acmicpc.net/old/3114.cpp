#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MN=1503;
ll arrA[MN][MN], arrB[MN][MN];
ll psumA[MN][MN], psumB[MN][MN];
ll dp[MN][MN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll R, C; cin>>R>>C;
    for(ll i=1; i<=R; ++i){
        for(ll j=1; j<=C; ++j){
            string str; cin>>str;
            ll t=0;
            for(ll k=1; k<str.size(); ++k){
                t=t*10+str[k]-'0';
            }
            if(str[0]=='A') arrA[i][j]=t;
            else arrB[i][j]=t;
        }
    }
    for(ll i=1; i<=R; ++i){
        for(ll j=1; j<=C; ++j){
            psumA[i][j]=psumA[i][j-1]+arrA[i][j];
        }
        for(ll j=C; j>0; --j){
            psumB[i][j]=psumB[i][j+1]+arrB[i][j];
        }
    }
    for(ll j=1; j<=C; ++j){
        dp[1][j]=psumB[1][j+1];
    }
    for(ll i=2; i<=R; ++i){
        for(ll j=1; j<=C; ++j){
            ll topLeft = dp[i-1][j-1];
            ll up = dp[i-1][j];
            if(topLeft > up){
                dp[i][j]=topLeft + psumA[i][j-1] + psumB[i][j+1];
            }
            else{
                dp[i][j]=up + psumA[i][j-1] + psumB[i][j+1];
            }
            ll left = dp[i][j-1];
            if(left - arrB[i][j] > dp[i][j]){
                dp[i][j]=left-arrB[i][j];
            }
        }
    }
    cout << dp[R][C] << '\n';
}