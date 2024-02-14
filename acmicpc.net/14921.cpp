#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    ll res=1e18;
    sort(v.begin(), v.end());
    for(int i=0; i<v.size()-1; ++i){
        ll cur = v[N-i-1];
        auto lo=lower_bound(v.begin(), v.end()-i-1, -cur)-v.begin();
        if(lo<N-i-1){
            if(abs(res)>abs(cur+v[lo])) res=cur+v[lo];
        }
        if(lo-1>=0){
            if(abs(res)>abs(cur+v[lo-1])) res=cur+v[lo-1];
        }
    }
    cout << res << '\n';
}