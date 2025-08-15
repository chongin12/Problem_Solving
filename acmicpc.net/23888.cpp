#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a, d;
ll f(ll x){
    return a+d*(x-1);
}
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>d;
    ll q; cin>>q;
    while(q--){
        ll what; cin>>what;
        ll l, r; cin>>l>>r;
        if(what==1){
            cout << (f(l)+f(r))*(r-l+1)/2 << '\n';
        }
        else {
            if(d==0 || r==l) cout << f(l) << '\n';
            else cout << gcd(f(r), gcd(f(l), d)) << '\n';
        }
    }
}