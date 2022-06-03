#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 1000003;
pair<ll,ll> EEA(ll a, ll b){
	ll r0=a, r1=b;
	ll s0=1, s1=0;
	ll t0=0, t1=1;
	while(r1){
		ll q=r0/r1;
		ll r2=r0-r1*q;
		r0=r1;
		r1=r2;
		ll s2=s0-s1*q;
		s0=s1;
		s1=s2;
		ll t2=t0-t1*q;
		t0=t1;
		t1=t2;
	}
	return {s0,t0};
}
int main(){
    ll K; cin>>K;
    K--;
    ll A=2;
    ll spare=1;
    while(K>1){
        if(K%2){
            spare*=A;
            spare%=MOD;
        }
        A=A*A;
        A%=MOD;
        K/=2;
    }
    A=A*spare%MOD;
    ll B=((A*A)%MOD*2+MOD-2)%MOD;
    ll x=EEA(MOD,3).second;
    if(x<0) x+=MOD;
    ll res = (B*x)%MOD - (A-1) + MOD * 2;
    res+=MOD*2;
    cout << res%MOD << '\n';
}