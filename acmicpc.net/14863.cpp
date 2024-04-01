#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
ll dp[2][100001];
// 도보, 자전거 2택이 아니라, 미리 도보만큼 빼둔 값을 반영해두고, 
// 자전거를 택할지 말지만 결정.
vector<pii> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, K; cin>>N>>K;
    ll res=0;
    v.push_back({0,0});
    for(ll i=1; i<=N; ++i){
        ll a1, a2, b1, b2; cin >> a1>>a2>>b1>>b2;
        // 둘 중에 시간이 더 작은걸로 빼기
        if(a1<b1){
            v.push_back({b1-a1, b2-a2});
            K-=a1;
            res+=a2;
        }
        else {
            v.push_back({a1-b1, a2-b2});
            K-=b1;
            res+=b2;
        }
    }
    for(ll i=1; i<=N; ++i){
        for(ll j=0; j<v[i].first; ++j){
            dp[i%2][j]=dp[(i-1)%2][j];
        }
        for(ll j=v[i].first; j<=K; ++j){
            dp[i%2][j]=max(dp[(i-1)%2][j],dp[(i-1)%2][j-v[i].first]+v[i].second);
        }
    }
    cout << res + dp[N%2][K] << '\n';
}