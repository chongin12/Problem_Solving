#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Node {
    ll a, b, c;
};
vector<Node> v;
ll dp[1000001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, M, R; cin>>N>>M>>R;
    for(ll i=0; i<M; ++i){
        ll a, b, c; cin>>a>>b>>c;
        v.push_back({a,b+R,c});
    }
    sort(v.begin(), v.end(), [](Node a, Node b){
        if(a.b==b.b) return a.a<b.a;
        return a.b<b.b;
    });
    dp[0]=v[0].c;
    // for(auto it:v){
    //     cout << it.a << ", " << it.b << ", " << it.c << '\n';
    // }
    for(int i=1; i<M; ++i){
        auto idx = lower_bound(v.begin(), v.end(), Node({0,v[i].a+1,0}), [](Node a, Node b){
            return a.b<b.b;
        }) - v.begin();
        // cout << "idx : " << idx << '\n';
        dp[i]=dp[i-1];
        if(idx) {
            dp[i]=max(dp[i], dp[idx-1]+v[i].c);
        }
        else {
            dp[i]=max(dp[i], v[i].c);
        }
        // cout << "dp["<<i<<"]="<<dp[i]<<'\n';
    }
    cout << dp[M-1] << '\n';
}