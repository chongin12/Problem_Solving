#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll k=0;
    vector<ll> v;
    for(ll i=0; i<n; ++i){
        ll a; cin>>a;v.push_back(a);
        k+=a;
    }
    ll spare=k%n;
    k/=n;
    ll res=0;
    sort(v.begin(),v.end(),greater<ll>());
    for(ll i=0; i<n; ++i){
        if(v[i]<=k) break;
        if(spare){
            spare--;
            res+=v[i]-k-1;
        }
        else{
            res+=v[i]-k;
        }
    }
    cout << res << '\n';
}