#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[1000];
int main(){
    ll N; cin>>N;
    vector<ll> v;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    for(ll i=0; i<=v[0]; ++i){
        bool flag=true;
        arr[0]=i;
        for(ll j=0; j<N; ++j){
            arr[j+1]=v[j]-arr[j];
            if(arr[j+1]<0) {
                flag=false;
                break;
            }
        }
        if(v.back()!=arr[0]+arr[N-1]) flag=false;
        if(!flag) continue;
        for(ll j=0; j<N; ++j){
            cout << arr[j] << '\n';
        }
        break;
    }

}