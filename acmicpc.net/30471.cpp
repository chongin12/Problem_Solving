#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll p[200001];
ll r[200001];
ll cnt[200001];
void init(){
    for(ll i=1; i<200001; ++i){
        p[i]=i;
        cnt[i]=1;
        r[i]=r[i-1]+i;
    }
}
ll find(ll x){
    if(x==p[x]) return x;
    return p[x]=find(p[x]);
}
ll res=0;
void unite(ll x, ll y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(x>y) swap(x,y);
    res-=r[cnt[x]-1]+r[cnt[y]-1];
    res+=r[cnt[x]+cnt[y]-1];
    cnt[x]+=cnt[y];
    cnt[y]=0;
    p[y]=x;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, M; cin>>N>>M;
    init();
    for(ll i=0; i<M; ++i){
        ll a,b; cin>>a>>b;
        unite(a,b);
        cout << res+N << '\n';
    }
}