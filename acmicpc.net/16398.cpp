#include <bits/stdc++.h>
#define x first
#define y second.first
#define z second.second
using ll=long long;
using namespace std;
using piii=pair<ll, pair<ll,ll>>;
ll par[1001];
void init(){
    for(ll i=0; i<1001; ++i){
        par[i]=i;
    }
}
ll Find(ll a){
    if(par[a]==a) return a;
    return par[a]=Find(par[a]);
}
void Union(ll a, ll b){
    ll A=Find(a);
    ll B=Find(b);
    par[A]=B;
}
vector<piii> v;
int main(){
    init();
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=1; i<=N; ++i){
        for(ll j=1; j<=N; ++j){
            ll a; cin>>a;
            if(i>=j) continue;
            v.push_back({a,{i,j}});
        }
    }
    sort(v.begin(), v.end(), [](piii a, piii b){
        return a.first < b.first;
    });
    ll res=0;
    for(auto it:v){
        if(Find(it.y) != Find(it.z)){
            res+=it.x;
            Union(it.y, it.z);
        }
    }
    cout << res << '\n';
}