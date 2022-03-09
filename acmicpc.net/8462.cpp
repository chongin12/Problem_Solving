#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> v;
ll ans[100001];
ll sq;
ll cache[1000001]={};
struct Query {
    ll l, r, idx;
    Query(ll l, ll r, ll idx):l(l),r(r),idx(idx){}
};
bool cmp(Query a, Query b){
    if(a.l/sq == b.l/sq){
        return a.r < b.r;
    }
    return a.l/sq < b.l/sq;
}
vector<Query> q;
int main(){
    ll n, t; cin>>n>>t;
    sq=sqrt(n);
    for(ll i=0; i<n; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    for(ll i=0; i<t; ++i){
        ll l, r; cin>>l>>r; l--,r--;
        q.push_back(Query(l, r, i));
    }
    sort(q.begin(), q.end(), cmp);
    ll L=q[0].l, R=q[0].r, sum=0;
    for(ll i=L; i<=R; ++i){
        sum-=cache[v[i]]*cache[v[i]]*v[i];
        cache[v[i]]++;
        sum+=cache[v[i]]*cache[v[i]]*v[i];
    }
    ans[q[0].idx]=sum;
    for(ll i=1; i<t; ++i){
        ll nl=q[i].l, nr=q[i].r, nidx=q[i].idx;
        while(nl < L) {
            --L;
            sum-=cache[v[L]]*cache[v[L]]*v[L];
            cache[v[L]]++;
            sum+=cache[v[L]]*cache[v[L]]*v[L];
        }
        while(nl > L) { 
            sum-=cache[v[L]]*cache[v[L]]*v[L];
            cache[v[L]]--;
            sum+=cache[v[L]]*cache[v[L]]*v[L];
            L++;
        }
        while(nr < R) { 
            sum-=cache[v[R]]*cache[v[R]]*v[R];
            cache[v[R]]--;
            sum+=cache[v[R]]*cache[v[R]]*v[R];
            R--;
        }
        while(nr > R) { 
            ++R;
            sum-=cache[v[R]]*cache[v[R]]*v[R];
            cache[v[R]]++;
            sum+=cache[v[R]]*cache[v[R]]*v[R];
        }
        ans[nidx]=sum;
    }
    for(ll i=0; i<t; ++i){
        cout << ans[i] << '\n';
    }
}