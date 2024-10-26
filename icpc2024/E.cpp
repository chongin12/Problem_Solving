#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[1001][1001];
ll dp[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, M; cin>>N>>M;
    for(ll i=0; i<N; ++i){
        for(ll j=0; j<N; ++j){
            cin>>arr[i][j];
        }
    }
    for(ll i=0; i<N; ++i){
        for(ll j=0; j<N; ++j){
            ll a; cin>>a;
            arr[i][j]=abs(arr[i][j]-a);
        }
    }
    for(ll j=0; j<N; ++j){
        for(ll i=0; i<N; ++i){
            dp[j]=max(dp[j], arr[i][j]);
        }
    }
    ll res=0;
    for(ll i=0; i<M; ++i){
        ll a; cin>>a;
        res+=dp[a-1];
    }
    cout << res << '\n';
}