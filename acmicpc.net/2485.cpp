#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    vector<ll> v, v2;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    for(ll i=1; i<N; ++i){
        v2.push_back(v[i]-v[i-1]);
    }
    ll ret=v2[0];
    for(ll i=1; i<v2.size(); ++i){
        ret=gcd(ret,v2[i]);
    }
    ll res=0;
    for(auto it:v2){
        res+=it/ret-1;
    }
    cout << res << '\n';
}