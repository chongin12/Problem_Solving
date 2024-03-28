#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node {
    ll x, y, l, idx;
    node(ll x, ll y, ll l, ll idx):x(x),y(y),l(l),idx(idx){}
};
vector<node> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, M; cin>>N>>M;
    for(ll i=0; i<M; ++i){
        ll a,b; cin>>a>>b;
        if(b==0) b=N;
        if(a>b){
            v.push_back(node(a,N+b,N-a+b,i));
            v.push_back(node(0,b,N-a+b,i));
        }
        else{
            v.push_back(node(a,b,b-a,i));
        }
    }
    sort(v.begin(), v.end(), [](node a, node b){
        if(a.x==b.x && a.y==b.y) return a.l>b.l;
        if(a.x==b.x) return a.y>b.y;
        return a.x<b.x;
    });
    // for(auto it:v){
    //     cout << "("<<it.x<<", "<<it.y<<"), len : " << it.l << ", idx : " << it.idx << '\n';
    // }
    ll ymax=-1;
    vector<ll> res;
    for(ll i=0; i<v.size(); ++i){
        node cur = v[i];
        if(cur.y<=ymax) continue;
        ymax=cur.y;
        res.push_back(cur.idx);
    }
    sort(res.begin(), res.end());
    ll prv=-1;
    for(auto it:res){
        if(it==prv) continue;
        cout << it+1 << ' ';
        prv=it;
    }
    cout << '\n';
}