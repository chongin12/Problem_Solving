#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using pll=pair<ll,ll>;
const ll D=1000000007;
pll dp[300001];
vector<ll> v;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	for(int i=0; i<N; ++i){
		ll a; cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	ll res=0;
	for(int i=1; i<N; ++i){
		dp[i]={((v[i]-v[i-1])*(2*dp[i-1].second+1)%D+dp[i-1].first*2%D)%D,(2*dp[i-1].second+1)%D};
		res+=dp[i].first%D;
	}
	cout << res%D << '\n';
}