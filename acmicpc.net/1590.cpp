#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N, T; cin>>N>>T;
    vector<ll> v;
    for(ll i=0; i<N; ++i){
        ll s, l, c; cin>>s>>l>>c;
        for(ll j=0; j<c; ++j){
            v.push_back(s+l*j);
        }
    }
    sort(v.begin(), v.end());
    auto idx = lower_bound(v.begin(), v.end(), T) - v.begin();
    if(idx==v.size()) {
        cout << "-1\n";
    } else {
        cout << v[idx]-T << '\n';
    }
}