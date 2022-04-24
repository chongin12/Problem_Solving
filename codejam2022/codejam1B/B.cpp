#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll dp[1001][2] = {0,};
void init() {
    for(int i=0; i<1001; ++i){
        dp[i][0]=0;
        dp[i][1]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        init();
        int N, P; cin>>N>>P;
        vector<pair<ll, ll> > cache;
        for(int i=0; i<N; ++i){
            ll Min=0, Max=0;
            for(int j=0; j<P; ++j){
                ll a; cin>>a;
                if(j==0) {
                    Min=a;
                    Max=a;
                }
                else{
                    Min=min(Min,a);
                    Max=max(Max,a);
                }
            }
            cache.push_back({Min,Max});
        }
        ll prv0=cache[0].second, prv1=cache[0].first; // 0 : Min->Max, 1 : Max->Min
        dp[0][0]=cache[0].second;
        dp[0][1]=cache[0].second*2-cache[0].first;
        for(int i=1; i<N; ++i){
            // 1. prv1->Min->Max
            // 1. prv0->Min->Max
            ll a=dp[i-1][1]+abs(prv1-cache[i].second)+cache[i].second-cache[i].first;
            ll b=dp[i-1][0]+abs(prv0-cache[i].second)+cache[i].second-cache[i].first;
            dp[i][1]=min(a,b);
            // 0. prv0->Max->Min
            // 0. prv1->Max->Min
            ll c=dp[i-1][0]+abs(prv0-cache[i].first)+cache[i].second-cache[i].first;
            ll d=dp[i-1][1]+abs(prv1-cache[i].first)+cache[i].second-cache[i].first;
            dp[i][0]=min(c,d);
            prv0=cache[i].second;
            prv1=cache[i].first;
            // cout << "dp["<<i<<"]["<<0<<"]="<<dp[i][0]<<'\n';
            // cout << "dp["<<i<<"]["<<1<<"]="<<dp[i][1]<<'\n';
        }
        cout << "Case #"<<t<<": "<<min(dp[N-1][0], dp[N-1][1]) << '\n';
    }
}