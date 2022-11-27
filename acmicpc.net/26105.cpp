#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF = 0x7FFFFFFF;
vector<ll> v;
ll dp[100001]; // dp[i] : i번째까지 봤을 때 최대 길이
ll psum[100001];
ll sum(ll a, ll b){
    return psum[b]-psum[a-1];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    v.resize(N+1);
    psum[0]=0;
    v[0]=0;
    for(ll i=1; i<=N; ++i){
        cin>>v[i];
        psum[i]=psum[i-1]+v[i];
    }
    fill(dp, dp+N+1, INF);
    dp[0]=0;
    ll res=INF;
    for(ll i=1; i<=N; ++i){
        dp[i]=min(dp[i],dp[i-1]+v[i]);
        int lo=i+1, hi=N, t=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(psum[mid]-psum[i]>=dp[i])
                hi=mid-1, t=mid;
            else lo=mid+1;
        }
        if(t!=-1){
            dp[t]=min(dp[t],sum(i+1,t));
        }
        else{
            res=min(res,dp[i]);
        }
    }
    cout << min(res,dp[N]) << '\n';
}
/*
folding stick
dp[i] : i번째 막대까지 봤을 때 maximum 길이

i번째에서 :
i+1 ~ N 중 가장 최선으로 꺾을 수 있는 막대 선정.
해당 막대를 k라고 했을 때 dp[k] 값 갱신.

*/
