#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N, M; cin>>N>>M;
    ll r=0;
    ll minA=1987654321;
    for(ll i=0; i<N; ++i){
        for(ll j=0; j<M; ++j){
            ll a; cin>>a;
            minA=min(minA,a);
            r+=a;
        }
    }
    cout << r-minA << '\n';
}