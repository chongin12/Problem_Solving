#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[200011];
ll isOn[200011];
ll dp[200011]; // dp[i] : i번째를 무조건 뒤집을 때 연속 최대 밝기 합
ll acc[200011];
int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        cin>>arr[i];
    }
    for(ll i=0; i<N; ++i){
        cin>>isOn[i];
        if(i==0) acc[i]=arr[i]*isOn[i];
        else acc[i]=acc[i-1]+arr[i]*isOn[i];
    }
    dp[0]=arr[0]*(!isOn[0]);
    ll res=dp[0]+acc[N-1]-acc[0];
    for(ll i=1; i<N; ++i){
        dp[i]=max(dp[i-1],acc[i-1])+arr[i]*(!isOn[i]);
        res=max(res,dp[i]+acc[N-1]-acc[i]);
    }
    cout << res << '\n';
}