#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
struct node{
	ll a,b,bit; // a=실력, b=알고리즘 수, bit=알고리즘 종류
	node(ll a, ll b, ll bit):a(a),b(b),bit(bit){}
};
vector<node> v;
ll effi(int l, int r, int arr[]){
	int r1=0,r2=0;
	for(int i=1; i<=30; ++i){
		if(arr[i]) {
			r1++;
			if(arr[i]==r-l+1) r2++;
		}
	}
	return (r1-r2)*(r-l+1);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,K; ll D; cin>>N>>K>>D;
	for(int i=0; i<N; ++i){
		ll M, d; cin>>M>>d;
		ll t=0;
		for(int j=0; j<M; ++j){
			ll k; cin>>k;
			t+=(1<<k);
		}
		v.push_back(node(d,M,t));
	}
	sort(v.begin(), v.end(), [](node a, node b){
		return a.a<b.a;
	});
	int l=0,r=0;
	int arr[31]={0,};
	ll res=0;
	for(int i=1; i<=30; ++i){
		if(v[r].bit & (1<<i)) {
			arr[i]++;
		}
	}
	while(l<=r && r<v.size()){
		if(v[r].a-v[l].a>D){
			for(int i=1; i<=30; ++i){
				if(v[l].bit & (1<<i)) {
					arr[i]--;
				}
			}
			l++;
			continue;
		}
		// cout << "l : " << l << ", r : " << r << ", effi : " << effi(l,r,arr) << '\n';
		res=max(res,effi(l,r,arr));
		r++;
		for(int i=1; i<=30; ++i){
			if(v[r].bit & (1<<i)) {
				arr[i]++;
			}
		}
	}
	cout << res << '\n';
}