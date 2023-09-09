#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, L; cin>>N>>L;
    vector<pll> v;
    for(int i=0; i<N; ++i){
        ll a, b; cin>>a>>b;
        v.push_back({a, b-1});
    }
    sort(v.begin(), v.end());
    ll res=0;
    ll prev=-1;
    for(auto it:v){
        if(it.first <= prev){
            it.first = prev+1;
            if(it.first > it.second) continue;
        }
        prev = it.first - 1;
        ll cnt = (it.second - it.first+1)/L;
        if(it.second - it.first+1 > cnt*L){
            cnt+=1;
        }
        res+=cnt;
        prev=prev+cnt*L;
    }
    cout << res << '\n';
}