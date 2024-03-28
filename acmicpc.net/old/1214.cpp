#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll res;
ll imax,r,d,t;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll D,P,Q; cin>>D>>P>>Q;
	if(D%P==0 || D%Q==0) {
		cout << D << '\n';
		return 0;
	}
	if(Q>P) swap(P,Q); // P에 더 큰 값이 오게.
	else if(Q==P){
		if(D%Q) D+=Q-(D%Q);
		cout << D << '\n';
		return 0;
	}
	imax=D/P+1;
	res=P*imax;
	for(ll i=imax-1; i>=0; i-=1){
		r=D-i*P;
		d=r%Q;
		if(d==0) {
			res=D; break;
		}
		// cout << "i : " << i <<", r : " << r << ", i*P : " << i*P << '\n';
		if(r<0) r=0;
		if(r>0 && d) r+=Q-d;
		t=r+i*P;
		if(t==res) break;
		res=min(res,r+i*P);
		if(res==D) break;
	}
	cout << res << '\n';
}