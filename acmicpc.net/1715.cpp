#include <bits/stdc++.h>
using namespace std;
using ll=long long;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a;
        pq.push(a);
    }
    ll res=0;
    while(pq.size()>=2){
        ll k=0;
        k+=pq.top(); pq.pop();
        k+=pq.top(); pq.pop();
        res+=k;
        pq.push(k);
    }
    cout << res << '\n';
}