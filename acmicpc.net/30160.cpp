#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
vector<ll> resV;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a;
        v.push_back(a);
    }
    ll res=0;
    ll plusAcc=0;
    ll toAdd=0;
    for(ll i=0; i<N; ++i){
        plusAcc+=toAdd+v[i];
        res+=plusAcc;
        resV.push_back(res);
        toAdd+=v[i]*2;
    }
    for(auto it:resV){
        cout << it << " ";
    }
    cout << '\n';
}