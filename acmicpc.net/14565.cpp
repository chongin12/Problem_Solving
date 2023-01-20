#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod(ll a, ll b){
    return (a%b>=0) ? a : a+b;
}
tuple<ll,ll,ll> ext_gcd(ll a, ll b){
    if(b==0) return {a, 1, 0};
    auto [g,x,y] = ext_gcd(b, a%b);
    return {g, y, x-a/b*y};
}
ll inv(ll a, ll n){
    auto [g,x,y] = ext_gcd(a,n);
    if(a==0 || g!=1) return -1;
    return mod(x,n);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, a; cin>>n>>a;
    cout << mod(-a,n) << " " << inv(a,n) << '\n';
}