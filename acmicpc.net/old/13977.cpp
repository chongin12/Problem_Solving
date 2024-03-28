#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll p = 1000000007;
ll fact[4000001];
ll f(ll x, ll cnt){ // x^cnt
	// cout << "x : " << x << ", cnt : " << cnt << '\n';
	if(cnt==0) return 1;
	if(cnt==1) return x;
	ll t=f((x*x)%p,cnt/2);
	ll m=1;
	if(cnt%2==1) m=x;
	return (t*m)%p;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	fact[0]=1;
	fact[1]=1;
	for(ll i=2; i<4000001; i+=1){
		fact[i]=((fact[i-1]%p)*(i%p))%p;
	}
	int M; cin >>M;
	while(M--){
		ll N,K;cin>>N>>K;
		cout << ((fact[N]%p)*(f((fact[K]*fact[N-K])%p,p-2)%p))%p << '\n';
	}
}