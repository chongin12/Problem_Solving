#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[3][100001];
void init() {
    for(ll i=0; i<3; ++i){
        for(ll j=0; j<100001; ++j){
            dp[i][j]=987654321;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll cnt=0;
    while(1){
        cnt++;
        ll N; cin>>N;
        if(N==0) break;
        init();
        for(ll i=0; i<N; ++i){
            ll a,b,c; cin>>a>>b>>c;
            if(i==0) {
                dp[0][i]=987654321;
                dp[1][i]=b;
                dp[2][i]=dp[1][i] + c;
            }
            else{
                dp[0][i]=min(dp[0][i-1], dp[1][i-1])+a;
                dp[1][i]=min({dp[0][i-1], dp[1][i-1], dp[2][i-1], dp[0][i]})+b;
                dp[2][i]=min({dp[2][i-1], dp[1][i-1], dp[1][i]})+c;
            }
        }
        cout << cnt << ". " << dp[1][N-1] << '\n';
    }
}