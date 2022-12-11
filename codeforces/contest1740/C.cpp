#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    while(T--){
        ll N; cin>>N;
        vector<ll> v(N);
        for(ll i=0; i<N; ++i){
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        ll res=-1;
        for(int i=2; i<N; ++i){
            res=max(res,v[i]-v[i-1]+v[i]-v[0]);
        }
        for(int i=0; i<N-2; ++i){
            res=max(res,v[i+1]-v[i]+v[N-1]-v[i]);
        }
        cout << res << '\n';
    }
}