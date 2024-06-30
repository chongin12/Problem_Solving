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
    ll res=5;
    for(ll window=min(5LL,N); window>0; --window){
        for(ll i=0; i<=N-window; ++i){
            ll temp=0;
            for(ll j=1; j<window; ++j){
                temp+=v[i+j]-v[i+j-1]-1;
            }
            if(window+temp<5) temp+=5-window-temp;
            res=min(res,temp);
        }
    }
    cout << res << '\n';
}