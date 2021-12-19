#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
// vector<pll> v;
vector<ll> v;
int main(){
	ll n; cin>>n;
	ll t=n;
	ll cnt;
	ll res=n;
	bool pass=false;
	for(ll i=2; i*i<=n; ++i){
		pass=false;
		while(n%i==0){
			n/=i;
			pass=true;
		}
		if(pass){
			v.push_back(i);
		}
	}
	// if(n>1) v.push_back({n,1});
	if(n>1) v.push_back(n);
	ll m=(1<<v.size());
	ll bit=0;
	ll k,temp;
	for(ll i=1; i<m; ++i){
		bit=0; // i의 1비트를 센다.
		k=1; // res에 더하거나 뺄 게수를 센다.
		for(ll j=0; ; ++j){
			temp=(1<<j);
			if(temp>=m) break;
			if(i&temp) {
				bit++;
				k*=v[j];
			}
		}
		if(bit%2){
			res-=t/k;
		}
		else{
			res+=t/k;
		}
	}
	cout << res << '\n';
}