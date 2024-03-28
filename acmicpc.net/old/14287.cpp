#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN = 100001;
ll In[MN+1], Out[MN+1];
ll seg[MN*4+1];
vector<ll> G[MN+1];
ll Update(int idx, ll val, int n, int l, int r) {
    if(r<idx || idx<l) return seg[n];
    if(l==r) {
        seg[n]+=val;
        return seg[n];
    }
    int mid = (l+r)/2;
    return seg[n] = Update(idx, val, n*2, l, mid) + Update(idx, val, n*2+1, mid+1, r);
}

ll Query(int L, int R, int n, int l, int r) {
    if (r<L || R<l) return 0;
    if(L<=l && r<=R) return seg[n];
    int mid = (l+r)/2;
    return Query(L, R, n*2, l, mid) + Query(L, R, n*2+1, mid+1, r);
}
void dfs(ll x){
    static ll cnt=0;
    In[x]=++cnt;
    for(auto it:G[x]){
        dfs(it);
    }
    Out[x]=cnt;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    for(ll i=1; i<=n; ++i){
        ll a; cin>>a;
        if(i==1) continue;
        G[a].push_back(i);
    }
    dfs(1);
    while(m--){
        int ch; cin>>ch;
        if(ch==1){
            ll i, w; cin>>i>>w;
            Update(In[i],w,1,1,MN);
        }
        else{
            ll i; cin>>i;
            cout << Query(In[i],Out[i],1,1,MN) << '\n';
        }
    }
}