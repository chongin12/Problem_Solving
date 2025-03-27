#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N; cin>>N;
    vector<ll> v;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<ll>());
    cout << (v[0]+v[1])/2 << '\n';
}