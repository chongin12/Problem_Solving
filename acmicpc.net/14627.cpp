#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
ll f(ll k){
    ll ret=0;
    for(auto it:v){
        ret+=it/k;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll S, C; cin>>S>>C;
    for(ll i=0; i<S; ++i){
        ll a; cin>>a;
        v.push_back(a);
    }
    ll lo=1, hi=1000000001;
    while(lo<hi-1){
        ll mid = (lo+hi)/2;
        if(f(mid)>=C){
            lo=mid;
        }
        else {
            hi=mid;
        }
    }
    // cout << lo << " " << hi << '\n';
    ll ret=0;
    ll cnt=0;
    for(auto it:v){
        ret+=it%lo;
        cnt+=it/lo;
    }
    ret+=(cnt-C)*lo;
    cout << ret << '\n';
}