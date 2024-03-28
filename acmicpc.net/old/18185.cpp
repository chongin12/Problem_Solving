#include <bits/stdc++.h>
#define min3(a,b,c) min((a),min((b),(c)))
using namespace std;
using ll=long long int;
vector<ll> v;
struct node {
	ll a, b, c; // 비용 3, 비용 5, 비용 7
	node(ll a, ll b, ll c):a(a),b(b),c(c){}
};
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	for(int i=0; i<N; ++i){
		ll a; cin>>a; v.push_back(a);
	}
	ll res=3*v[0];
	
	node prev2(0,0,0); // i-1
	node prev1(v[0],0,0); // i
	for(int i=0; i<N-1; ++i){
		node prev0(0,0,0); // i+1
		// 1. prev1에서 비용 3으로 산거 일부를 prev0과 함께 비용 5로 계산한다.
		ll k=min(prev1.a, v[i+1]);
		res-=3*k;
		res+=5*k;
		prev1.a-=k;
		v[i+1]-=k;
		prev1.b+=k;
		prev0.b+=k;
		// 2. prev2와 prev1에서 비용 5로 산거 일부를 prev0과 함께 비용 7로 계산한다.
		if(i!=0){
			ll k=min3(prev2.b, prev1.b, v[i+1]);
			res-=5*k;
			res+=7*k;
			prev2.b-=k;
			prev1.b-=k;
			v[i+1]-=k;
			prev2.c+=k;
			prev1.c+=k;
			prev0.c+=k;
		}
		// 3. 남은걸 prev0에 비용 3으로 산다.
		prev0.a+=v[i+1];
		res+=3*v[i+1];
		prev2=prev1;
		prev1=prev0;
	}
	cout << res << '\n';
}