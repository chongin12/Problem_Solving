#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N, L, R, X; cin>>N>>L>>R>>X;
    vector<ll> v;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    ll res=0;
    for(ll i=0; i<(1<<N); ++i){
        ll sum=0;
        ll max_=-1, min_=987654321;
        ll cnt=0;
        for(ll j=0; j<N; ++j){
            if(i&(1<<j)){
                sum+=v[j];
                max_=max(max_, v[j]);
                min_=min(min_, v[j]);
                cnt++;
            }
        }
        // cout << "i : " << i << '\n';
        // cout << "sum : " << sum << ", max_="<<max_<<", min_="<<min_<<'\n';
        if(cnt<2) continue;
        if(sum>=L && sum<=R && max_-min_>=X){
            res++;
        }
    }
    cout << res << '\n';
}