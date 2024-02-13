#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
vector<pii> G[10000];
ll N, Q;
ll k;
ll dfs(ll v, ll tempK, ll prev){
    ll ret=0;
    for(auto it:G[v]){
        if(it.first==prev) continue;
        ll nextTempK=min(tempK, it.second);
        if(nextTempK>=k) ret+=1;
        ret+=dfs(it.first, nextTempK, v);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>Q;
    for(ll i=0; i<N-1; ++i){
        ll p, q, r; cin>>p>>q>>r;
        G[p].push_back({q,r});
        G[q].push_back({p,r});
    }
    while(Q--){
        ll v; cin>>k>>v;
        cout << dfs(v, k, -1) << '\n';
    }
}