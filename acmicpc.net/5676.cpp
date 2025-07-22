#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN = 100001;
ll seg[MN*4+1];
ll Update(ll idx, ll val, ll n, ll n_left, ll n_right){
    if(idx<n_left || n_right<idx) return seg[n];
    if(n_left==n_right) return seg[n]=val;
    ll mid = (n_left+n_right)/2;
    return seg[n]=Update(idx, val, n*2, n_left, mid) * Update(idx, val, n*2+1, mid+1, n_right);
}
ll Query(ll left, ll right, ll n, ll n_left, ll n_right){
    if(left<=n_left && n_right<=right) return seg[n];
    if(right<n_left || n_right<left) return 1;
    ll mid = (n_left+n_right)/2;
    return Query(left, right, n*2, n_left, mid) * Query(left, right, n*2+1, mid+1, n_right);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, K;
    while(cin>>N>>K){
        for(int i=1; i<=N; ++i){
            int a; cin>>a;
            int temp=0;
            if(a>0) temp=1;
            else if(a<0) temp=-1;
            Update(i, temp, 1, 1, N);
        }
        while(K--){
            char what; cin>>what;
            if(what=='C'){
                int i, V; cin>>i>>V;
                int temp=0;
                if(V>0) temp=1;
                else if(V<0) temp=-1;
                Update(i, temp, 1, 1, N);
            } else {
                int i, j; cin>>i>>j;
                int temp=Query(i, j, 1, 1, N);
                if(temp>0) cout << "+";
                else if(temp==0) cout << "0";
                else cout << "-";
            }
        }
        cout << '\n';
    }
}