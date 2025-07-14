#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
map<pii, ll> m;
ll pr=1987654321;
ll p[200001];
void init(){
    for(ll i=0; i<200001; ++i){
        p[i]=i;
    }
}
ll Find(ll x){
    if(p[x]==x) return x;
    return p[x]=Find(p[x]);
}
void Union(ll a, ll b){
    a=Find(a);
    b=Find(b);
    p[a]=b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    ll cur=-1;
    init();
    for(ll i=0; i<N; ++i){
        ll a; cin>>a;
        if(pr>=a){
            ++cur;
        }
        pr=a;

        m[{cur, a}]=i;
        if(m.find({cur-1,a}) != m.end()){
            Union(m[{cur-1,a}], i);
        }
        if(m.find({cur,a-1}) != m.end()){
            Union(m[{cur,a-1}], i);
        }
        
    }
    set<ll> resS;
    for(ll i=0; i<N; ++i){
        resS.insert(Find(i));
    }
    cout << resS.size() << '\n';
    cout << N << '\n';
}