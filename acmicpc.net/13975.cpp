#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    while(T--){
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll K; cin>>K;
        for(ll i=0; i<K; ++i){
            ll a; cin>>a;
            pq.push(a);
        }
        ll res=0;
        while(pq.size()!=1){
            ll a=pq.top(); pq.pop();
            ll b=pq.top(); pq.pop();
            res+=a+b;
            pq.push(a+b);
        }
        cout << res << '\n';
    }
}