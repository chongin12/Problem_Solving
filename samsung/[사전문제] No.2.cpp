#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF = 2e18;
ll dp[51][51][51];
// dp[i][j][k] : i명까지 봤을 때 a는 j명, b는 k명 줬을 때 능력치 합산 최솟값.
void init(){
    for(ll i=0; i<51; ++i){
        for(ll j=0; j<51; ++j){
            for(ll k=0; k<51; ++k){
                dp[i][j][k]=INF;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    for(ll t=1; t<=T; ++t){
        init();
        ll N; cin>>N;
        for(ll i=1; i<=N; ++i){
            ll a, b, c; cin>>a>>b>>c;
            if(i==1){
                dp[1][1][0]=b+c;
                dp[1][0][1]=a+c;
                dp[1][0][0]=a+b;
            }
            else{
                for(ll j=0; j<=i; ++j){
                    for(ll k=0; k<=i; ++k){
                        if(j+k>i) break;
                        if(j!=0){ // a를 줬을 때
                            dp[i][j][k]=min(dp[i][j][k], dp[i-1][j-1][k]+b+c);
                        }
                        if(k!=0){
                            dp[i][j][k]=min(dp[i][j][k], dp[i-1][j][k-1]+a+c);
                        }
                        if(i-j-k!=0){
                            dp[i][j][k]=min(dp[i][j][k], dp[i-1][j][k]+a+b);
                        }
                    }
                }
            }
        }
        ll res=INF;
        for(ll i=1; i<N; ++i){
            for(ll j=1; j<N; ++j){
                if(i+j>=N) break;
                res=min(res,dp[N][i][j]);
            }
        }
        cout << "#" << t << " " << (res == INF ? -1 : res) << '\n';
    }
}