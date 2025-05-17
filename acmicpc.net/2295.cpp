#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
set<ll> hap, cha;
set<ll> res;
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        ll a; cin>>a;
        v.push_back(a);
    }
    for(int i=0; i<N; ++i){
        for(int j=i; j<N; ++j){
            hap.insert(v[i]+v[j]);
            cha.insert(abs(v[i]-v[j]));
        }
    }
    for(auto it:hap){
        if(cha.find(it)!=cha.end()){
            res.insert(it);
        }
    }
    ll _max=0;
    for(int i=0; i<N; ++i){
        for(int j=i; j<N; ++j){
            if(res.find(abs(v[i]-v[j]))!=res.end()){
                _max=max(_max,max(v[i],v[j]));
            }
        }
    }
    cout << _max << '\n';
}