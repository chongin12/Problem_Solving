#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v1, v2;
ll dp[2002][2002];
ll res=-2e18;
int B=-1, E=-1;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v1.push_back(a);
    }
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v2.push_back(a);
        dp[i][i]=v1[i]*v2[i];
        if(i>0){
            dp[i-1][i]=v1[i-1]*v2[i]+v1[i]*v2[i-1];
            if(res<dp[i-1][i]){
                res=dp[i-1][i];
                B=i-1, E=i;
            }
        }
        if(res<dp[i][i]){
            res=dp[i][i];
            B=i, E=i;
        }
    }
    for(ll k=3; k<=N; ++k){
        for(ll i=0; i<N; ++i){
            ll j=i+k-1;
            if(j>=N) break;
            // cout << "\ndp["<<i+1<<"]["<<j-1<<"]="<<dp[i+1][j-1]<<'\n';
            dp[i][j]=dp[i+1][j-1]+v1[i]*v2[j]+v1[j]*v2[i];
            // cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
            if(res<dp[i][j]){
                res=dp[i][j];
                B=i, E=j;
            }
        }
    }
    cout << B << " " << N-E-1 << '\n';
    cout << res << '\n';
}