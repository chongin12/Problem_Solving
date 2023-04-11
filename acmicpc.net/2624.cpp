#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
vector<pii> v;
ll dp[10101][111]; // dp[i][j] : i원을 k번째 동전까지 봤을 때 만들 수 있는 개수 
ll f(ll x, ll k){ // x원, k번째 동전 
//	cout << "x : " << x << ", k : " << k << '\n';
	if(x<0 || k<0) return 0;
	if(dp[x][k]!=-1) return dp[x][k];
	dp[x][k]=0;
	ll ret=0;
	ll money = v[k].first;
	ll count = v[k].second;
	for(ll i=count; i>=1; --i){
		if(x-money*i<0) continue;
		ret+=f(x-money*i, k-1);
	}
	ret+=f(x, k-1);
//	cout << "dp["<<x<<"]["<<k<<"]="<<ret<<'\n';
	return dp[x][k] = ret;
}
void init(){
	for(ll i=0; i<10101; ++i)
		for(ll j=0; j<111; ++j)
			dp[i][j]=-1;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	ll T, k; cin>>T>>k;
	for(ll i=0; i<k; ++i){
		ll p, n; cin>>p>>n;
		if(i==0){
			for(ll j=0; j<=T; ++j){
				dp[j][0]=0;
			}
			for(ll j=0; j<=n; ++j){
				if(p*j<10101) dp[p*j][0]=1;	
			}
		}
		v.push_back({p,n});
	}
	cout << f(T, k-1) << '\n';
}