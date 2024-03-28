#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> v;
int main(){
	int n;cin>>n;
	for(int i=0; i<n; ++i){
		ll a;cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	ll sel=1110987654321;
	ll s[3]={0,};
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			ll t=v[i]+v[j];
			int pos=lower_bound(v.begin(), v.end(), -t)-v.begin();
			for(int k=0; k<4; ++k){
				if(pos+k>=0 && pos+k<n && pos+k!=i && pos+k!=j){
					if(abs(sel)>abs(t+v[pos+k])) {
						sel=t+v[pos+k];
						s[0]=v[i],s[1]=v[j],s[2]=v[pos+k];
					}
				}
				if(pos-k>=0 && pos-k<n && pos-k!=i && pos-k!=j){
					if(abs(sel)>abs(t+v[pos-k])) {
						sel=t+v[pos-k];
						s[0]=v[i],s[1]=v[j],s[2]=v[pos-k];
					}
				}
			}
		}
	}
	sort(s,s+3);
	cout << s[0] << " " << s[1] << " " << s[2] << '\n';
}