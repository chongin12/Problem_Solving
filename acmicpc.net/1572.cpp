#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MN=100000;
ll seg[MN*4+1];
vector<ll> arr;
ll Query(ll L, ll R, ll n, ll l, ll r){ // L~R 사이 속한 원소 개수
    if(r<L || R<l) return 0;
    if(L<=l && r<=R) {
        return seg[n];
    }
    ll mid = (l+r)/2;
    return Query(L, R, n*2, l, mid)+Query(L, R, n*2+1, mid+1, r);
}
ll Update(ll A, ll v, ll n, ll l, ll r){ // A += v 으로 갱신
    if(A<l || r<A) return seg[n];
    if(l==r) { 
        seg[n]+=v;
        return seg[n]; 
    }
    ll mid = (l+r)/2;
    return seg[n]=Update(A, v, n*2, l, mid) + Update(A, v, n*2+1, mid+1, r);
}
ll f(ll L, ll R, ll k){ // L~R 구간에서 k번째로 작은 원소 값.
    if(L==R) return L;
    ll mid=(L+R)/2;
    ll q=Query(L, mid, 1, 1, MN);
    if(q>=k){
        return f(L, mid, k);
    }
    else {
        return f(mid+1, R, k-q);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, K; cin>>N>>K;
    ll res=0;
    for(ll i=1; i<=N; ++i){
        ll a; cin>>a;
        a++;
        arr.push_back(a);
        Update(a, 1, 1, 1, MN);
        if(i>=K) {
            if(i>K){
                Update(arr[i-K-1], -1, 1, 1, MN);
            }
            res+=f(1, MN, (K+1)/2)-1;
        }
    }
    cout << res << '\n';
}