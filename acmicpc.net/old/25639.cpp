#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MN=100001;
const ll INF=3087654321LL;
struct node {
    ll Min, Max, Inc;
    node():Min(INF), Max(-INF), Inc(0){}
    node(ll Min, ll Max, ll Inc):Min(Min),Max(Max),Inc(Inc){}
} seg[MN*4+1];
vector<node> v;
ll N;
node Update(ll idx, ll val, ll n, ll l, ll r){
    if(idx<l || r<idx) return seg[n];
    if(l==r) return seg[n]=node(val,val,0);
    ll mid=(l+r)/2;
    node left=Update(idx, val, n*2, l, mid), right=Update(idx, val, n*2+1, mid+1, r);
    return seg[n]=node(min(left.Min, right.Min), max(left.Max, right.Max), max({left.Inc, right.Inc, right.Max-left.Min}));
}
void Query(ll L, ll R, ll n, ll l, ll r){
    if(R<l || r<L) return;
    if(L<=l && r<=R) {
        v.push_back(seg[n]);
        return;
    }
    ll mid=(l+r)/2;
    Query(L, R, n*2, l, mid);
    Query(L, R, n*2+1, mid+1, r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(ll i=1; i<=N; ++i){
        ll a; cin>>a;
        Update(i, a, 1,1 ,N);
    }
    ll Q; cin>>Q;
    while(Q--){
        ll q; cin>>q;
        if(q==1){
            ll k, x; cin>>k>>x;
            Update(k,x,1,1,N);
        }
        else{
            v.clear();
            ll l, r; cin>>l>>r;
            Query(l,r,1,1,N);
            node temp=v[0];
            for(int i=1; i<v.size(); ++i){
                temp=node(min(temp.Min, v[i].Min), max(temp.Max, v[i].Max), max({temp.Inc, v[i].Inc, v[i].Max-temp.Min}));
            }
            cout << temp.Inc << '\n';
        }
    }
}