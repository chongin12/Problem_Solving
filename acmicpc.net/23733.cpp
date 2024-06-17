#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[19][19][19]; 
// i번째까지 왔을 때 첫 번째는 j, 두 번째는 k까지 채웠을 때 sum
void init(){
    for(ll i=0; i<19; ++i){
        for(ll j=0; j<19; ++j){
            for(ll k=0; k<19; ++k){
                dp[i][j][k]=0;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    while(T--){
        init();
        ll N, K; cin>>N>>K;
        string str; cin>>str;
        reverse(str.begin(), str.end());
        dp[0][0][0]=0;
        dp[1][1][0]=str[0]-'0';
        dp[1][0][1]=str[0]-'0';
        for(ll i=2; i<=N; ++i){
            ll now=str[i-1]-'0';
            for(ll j=0; j<=K; ++j){
                ll k=i-j;
                if(k<0) break;
                if(j==0){
                    dp[i][j][k]=dp[i-1][j][k-1]+now*(ll)pow(10,k-1);
                }
                else if(k==0){
                    dp[i][j][k]=dp[i-1][j-1][k]+now*(ll)pow(10,j-1);
                }
                else {
                    dp[i][j][k]=max(dp[i-1][j-1][k]+now*(ll)pow(10,j-1), dp[i-1][j][k-1]+(str[i-1]-'0')*(ll)pow(10,k-1));
                }
            }
        }
        ll res=0;
        res=max(dp[N][K][N-K], dp[N][N-K][K]);
        cout << res << '\n';
    }
}