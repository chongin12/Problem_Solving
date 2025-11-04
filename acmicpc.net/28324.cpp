#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    vector<ll> v;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    ll cnt=1;
    v[N-1]=1;
    for(int i=N-2; i>=0; --i){
        if(v[i]<=v[i+1]){
            cnt+=v[i];
        }
        else{
            v[i]=min(v[i], v[i+1]+1);
            cnt+=v[i];
        }
    }
    cout << cnt << '\n';
}