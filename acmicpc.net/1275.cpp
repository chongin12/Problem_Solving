#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN = 100001;
ll seg[MN*4+1];
ll Update(ll idx, ll val, ll n, ll n_left, ll n_right){
    if(idx<n_left || n_right<idx) return seg[n];
    if(n_left==n_right) return seg[n]=val;
    ll mid = (n_left+n_right)/2;
    return seg[n]=Update(idx, val, n*2, n_left, mid) + Update(idx, val, n*2+1, mid+1, n_right);
}
ll Query(ll left, ll right, ll n, ll n_left, ll n_right){
    if(left<=n_left && n_right<=right) return seg[n];
    if(right<n_left || n_right<left) return 0;
    ll mid = (n_left+n_right)/2;
    return Query(left, right, n*2, n_left, mid) + Query(left, right, n*2+1, mid+1, n_right);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, Q; cin>>N>>Q;
    for(ll i=1; i<=N; ++i){
        ll a; cin>>a;
        Update(i, a, 1, 1, N);
    }
    while(Q--){
        ll x,y,a,b; cin>>x>>y>>a>>b;
        if(x>y) swap(x,y);
        cout << Query(x, y, 1, 1, N) << '\n';
        Update(a,b,1,1,N);
    }
}