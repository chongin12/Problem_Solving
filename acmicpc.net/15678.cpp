#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N, D;
ll res=-1e18;
struct node {
    ll value;
    ll idx;
    node(ll value, ll idx):value(value), idx(idx){}
};
struct comp {
    bool operator()(node a, node b){
        return a.value<b.value;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>D;
    priority_queue<node, vector<node>, comp> pq;
    vector<ll> v(N);
    for(ll i=0; i<N; ++i){
        cin>>v[i];
    }
    for(ll i=0; i<N; ++i){
        ll a=v[i];
        if(pq.empty()){
            res=max(res,a);
            pq.push(node(a, i));
            continue;
        }
        node cur = pq.top();
        if(cur.idx < i-D){
            --i;
            pq.pop();
            continue;
        }
        pq.push(node(a,i));
        pq.push(node(cur.value+a,i));
        res=max({res, cur.value+a, a});
    }
    cout << res << '\n';
}