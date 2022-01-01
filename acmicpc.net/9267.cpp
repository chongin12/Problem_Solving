/*
확장 유클리드 알고리즘
GCD(a,b)=d일 때,
ax+by=d를 만족하는 x,y를 찾아야 한다.
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
struct node{
	ll r,s,t;
	node(ll r, ll s, ll t):r(r),s(s),t(t){}
};
node EEA(ll a, ll b){
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
	return node(r0,s0,t0);
}
int main(){
	ll a,b,c; cin>>a>>b>>c;
	node ans=EEA(a,b);
	if(c%ans.r==0){
		cout << ans.r << " : " <<ans.s <<", "<<ans.t<<'\n';
	}
	else{
		cout << "NO\n";
	}
}