#include <bits/stdc++.h>
#define min3(a,b,c) min((a),min((b),(c)))
using namespace std;
using ll=long long int;
vector<ll> v;
struct node {
	ll a, b, c; // 비용 B, 비용 B+C, 비용 B+2C
	node(ll a, ll b, ll c):a(a),b(b),c(c){}
};
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N, B, C; cin>>N>>B>>C;
	for(int i=0; i<N; ++i){
		ll a; cin>>a; v.push_back(a);
	}
	ll res=B*v[0];
	if(B*2<=B+C){
		res=0;
		for(int i=0; i<N; ++i){
			res+=v[i]*B;
		}
		cout << res << '\n';
		return 0;
	}
	node prev2(0,0,0); // i-1
	node prev1(v[0],0,0); // i
	for(int i=0; i<N-1; ++i){
		node prev0(0,0,0); // i+1
		// 1. prev1에서 비용 B으로 산거 일부를 prev0과 함께 비용 B+C로 계산한다.
		ll k=min(prev1.a, v[i+1]);
		res-=B*k;
		res+=(B+C)*k;
		prev1.a-=k;
		v[i+1]-=k;
		prev1.b+=k;
		prev0.b+=k;
		// 2. prev2와 prev1에서 비용 B+C로 산거 일부를 prev0과 함께 비용 B+C+C로 계산한다.
		if(i!=0){
			ll k=min3(prev2.b, prev1.b, v[i+1]);
			res-=(B+C)*k;
			res+=(B+C+C)*k;
			prev2.b-=k;
			prev1.b-=k;
			v[i+1]-=k;
			prev2.c+=k;
			prev1.c+=k;
			prev0.c+=k;
		}
		// 3. 남은걸 prev0에 비용 B으로 산다.
		prev0.a+=v[i+1];
		res+=B*v[i+1];
		prev2=prev1;
		prev1=prev0;
	}
	cout << res << '\n';
}