#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll arr1[1001][1001]; // arr[i][j] = i~j 합
ll arr2[1001][1001];
vector<ll> v;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll T; cin>>T;
	ll n,m; 
	cin>>n;
	for(int i=0; i<n; ++i){
		ll a; cin>>a;
		if(i==0) arr1[0][0]=a;
		else {
			for(int j=0; j<=i; ++j){
				arr1[j][i]=arr1[j][i-1]+a;
			}
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=i; j<n; ++j){
			//cout << "arr1["<<i<<"]["<<j<<"]="<<arr1[i][j]<<'\n';
			v.push_back(arr1[i][j]);
		}
	}
	sort(v.begin(), v.end());
	cin>>m;
	for(int i=0; i<m; ++i){
		ll a; cin>>a;
		if(i==0) arr2[0][0]=a;
		else {
			for(int j=0; j<=i; ++j){
				arr2[j][i]=arr2[j][i-1]+a;
			}
		}
	}
	ll res=0;
	for(int i=0; i<m; ++i){
		for(int j=i; j<m; ++j){
			//cout << "arr2["<<i<<"]["<<j<<"]="<<arr2[i][j]<<'\n';
			ll pos1 = lower_bound(v.begin(), v.end(), T-arr2[i][j])-v.begin();
			ll pos2 = upper_bound(v.begin(), v.end(), T-arr2[i][j])-v.begin();
			res+=pos2-pos1;
		}
	}
	cout << res << '\n';
}