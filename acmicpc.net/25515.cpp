#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> G[100001];
ll arr[1000001];
ll f(ll x, ll prev){
    ll ret=arr[x];
    for(auto nxt:G[x]){
        if(nxt==prev) continue;
        ll temp = f(nxt, x);
        if(temp>0) ret+=temp;
    }
    if(x!=0 && ret<=0) return 0;
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N-1; ++i){
        ll u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(ll i=0; i<N; ++i){
        cin>>arr[i];
    }
    cout << f(0, -1) << '\n';
}