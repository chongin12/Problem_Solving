#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n; cin>>n;
    ll res=0;
    for(ll i=1; n/i>=i; ++i){
        ll k=n/i;
        res+=k-i+1;
    }
    cout << res << '\n';
}