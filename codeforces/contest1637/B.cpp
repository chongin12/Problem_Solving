#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        vector<ll> idx;
        ll n; cin>>n;
        vector<ll> v;
        for(ll i=0; i<n; ++i){
            ll a; cin>>a;
            v.push_back(a);
            if(a==0) idx.push_back(i);
        }
        ll res=0;
        for(ll i=1; i<=n; ++i){
            for(ll j=0; j<n; ++j){ // j부터 i개
                if(j+i-1>=n) break;
                res+=i;
                for(auto it:idx){
                    if(j<=it && it<=j+i-1) res+=1;
                    if(it>j+i-1) break;
                }
                // cout << j << " ~ " << j+i-1 << " -> res : " << res << '\n';
            }
        }
        cout << res << '\n';
    }
}