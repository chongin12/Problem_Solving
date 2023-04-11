#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
const ll MN = 1e18;
ll N, M;
ll f(ll x){
    ll ret=0;
    for(auto it:v){
        ret+=x/it;
        if(ret>MN) break;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    ll lo=0, hi=2*MN;
    while(lo<hi-1){
        ll mid = (lo+hi)/2;
        if(f(mid)>=M) hi=mid;
        else lo=mid; 
    }
    cout << hi << '\n';
}