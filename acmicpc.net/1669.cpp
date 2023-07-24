#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll delta;
int f(ll x){
    ll k=x*(x-1)/2;
    if(2*k+x>=delta) return 1;
    if(2*(k+x)>=delta) return 2;
    return 0;
}
int main(){
    ll X, Y; cin>>X>>Y;
    delta = Y-X;
    if(delta==0) {
        cout << "0\n";
        return 0;
    }
    ll lo=0, hi=(1LL<<32LL)-1;
    while(lo<hi-1){
        ll mid=(lo+hi)/2;
        if(f(mid)) hi=mid;
        else lo=mid;
    }
    if(f(hi)==1) cout << 2*hi-1 << '\n';
    else cout << 2*hi << '\n';
}