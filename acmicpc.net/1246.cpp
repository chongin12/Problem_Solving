#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N, M; cin>>N>>M;
    vector<ll> v;
    for(ll i=0; i<M; ++i){
        ll a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll maxi=0;
    for(int i=0; i<N; ++i){
        if((i+1)*v[i] > (maxi+1)*v[maxi]){
            maxi=i;
        }
    }
    cout << v[maxi] << " " << (maxi+1)*v[maxi]<<'\n';
}