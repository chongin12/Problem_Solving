#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    ll r=0;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a;
        r+=a;
    }
    cout << r-(N*(N-1)/2) << '\n';
}