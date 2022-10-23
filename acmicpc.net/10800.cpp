#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node {
    ll i, c, s;
    node(ll i, ll c, ll s):i(i),c(c),s(s){}
};
vector<node> v;
ll acc[200101];
ll total;
ll res[200101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(ll i=1; i<=N; ++i){
        ll c,s; cin>>c>>s;
        v.push_back(node(i,c,s));
    }
    sort(v.begin(), v.end(), [](node a, node b){ return a.s<b.s; });
    vector<pair<ll,ll>> q; // {s, c}
    ll prevs=-1;
    for(auto it:v){
        if(it.s!=prevs){
            while(!q.empty()){
                pair<ll,ll> p=q.back(); q.pop_back();
                total+=p.first;
                acc[p.second]+=p.first;
            }
            prevs=it.s;
        }
        q.push_back({it.s, it.c});
        res[it.i]=total-acc[it.c];
    }
    for(int i=1; i<=N; ++i){
        cout << res[i] << '\n';
    }
}