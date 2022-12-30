#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    while(T--){
        ll n,m; cin>>n>>m;
        priority_queue<ll> pq;
        for(ll i=0; i<n; ++i){
            ll a; cin>>a; pq.push(-a);
        }
        for(ll i=0; i<m; ++i){
            ll a; cin>>a;
            pq.pop();
            pq.push(-a);
        }
        ll res=0;
        while(!pq.empty()){
            res+=-pq.top();
            pq.pop();
        }
        cout << res << '\n';
    }
}