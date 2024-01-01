#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
ll dp[101][2][21];
// dp[i][j][k] : i번째까지 봤을 때, i번째 연산을 j할때(+,-)
// k를 만드는 경우의 수.
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    dp[0][0][v[0]]=1;
    for(ll i=1; i<N-1; ++i){
        for(ll j=0; j<=20; ++j){
            if(j+v[i]<=20){
                dp[i][0][j+v[i]]+=dp[i-1][0][j]+dp[i-1][1][j];
            }
        }
        for(ll j=0; j<=20; ++j){
            if(j-v[i]>=0){
                dp[i][1][j-v[i]]+=dp[i-1][0][j]+dp[i-1][1][j];
            }
        }
        
    }
    cout << dp[N-2][0][v.back()] + dp[N-2][1][v.back()] << '\n';

}