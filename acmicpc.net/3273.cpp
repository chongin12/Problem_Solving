#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
int main(){
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    ll X; cin>>X;
    ll res=0;
    for(ll i=0; i<X/2; ++i){
        auto a = upper_bound(v.begin(), v.end(), i) - lower_bound(v.begin(), v.end(), i);
        if(a==0) continue;
        auto b = upper_bound(v.begin(), v.end(), X-i) - lower_bound(v.begin(), v.end(), X-i);
        if(b==0) continue;
        res+=a*b;
    }
    if(X%2){
        ll i=X/2;
        auto a = upper_bound(v.begin(), v.end(), i) - lower_bound(v.begin(), v.end(), i);

        auto b = upper_bound(v.begin(), v.end(), X-i) - lower_bound(v.begin(), v.end(), X-i);

        res+=a*b;
    }
    else{
        auto a = upper_bound(v.begin(), v.end(), X/2) - lower_bound(v.begin(), v.end(), X/2);
        res+=a*(a-1)/2;
    }
    cout << res << '\n';
}