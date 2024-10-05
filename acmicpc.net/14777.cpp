#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
vector<pii> v;
ll G[401][401];
ll dp[401]; // dp[i] = i번째를 꼭 포함할 때 최대 상품 개수
int main(){
    ll N; cin>>N;
    for(ll i=1; i<=N; ++i){
        ll a; cin>>a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    for(ll i=1; i<=N; ++i){
        for(ll j=1; j<=N; ++j){
            cin>>G[i][j];
        }
    }
    ll res=1;
    for(ll i=0; i<N; ++i){
        ll time = v[i].first;
        ll booth = v[i].second;
        // cout << "i="<<i<<'\n';
        // cout << "time : " << time << ", booth : " << booth << '\n';
        if(G[1][booth] <= time){
            dp[i] = 1;
        }
        for(ll j=0; j<i; ++j){
            ll prevTime = v[j].first;
            ll prevBooth = v[j].second;
            // cout << " j="<<j<<'\n';
            // cout << " prevtime : " << prevTime << ", booth : " << prevBooth << '\n';
            if(prevTime+G[prevBooth][booth]<=time){
                dp[i]=max(dp[i],dp[j]+1);
                // cout << "  dp["<<i<<"]="<<dp[i]<<'\n';
            }
        }
        // cout << "dp["<<i<<"]="<<dp[i]<<'\n';
        res=max(res,dp[i]);
    }
    cout << res << '\n';
}