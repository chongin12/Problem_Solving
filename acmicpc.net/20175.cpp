#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,d; cin>>n>>d;
    ll MX=-1e18,MN=1e18;
    vector<ll> v;
    for(ll i=0; i<n; ++i){
        ll a; cin>>a;
        v.push_back(a);
        MX=max(MX,a-i*d);
        MN=min(MN,a-i*d);
    }
    ll res1=MX-MN;
    MX=-1e18,MN=1e18;
    reverse(v.begin(), v.end());
    for(ll i=0; i<n; ++i){
        ll a=v[i];
        MX=max(MX,a-i*d);
        MN=min(MN,a-i*d);
    }
    ll res2=MX-MN;
    ll res=min(res1,res2);
    cout << res/2;
    if(res%2==1) cout << ".5";
    else cout << ".0";
    cout << '\n';
}