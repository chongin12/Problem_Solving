#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=100000;
ll seg[MN*4+1], lazy[MN*4+1];
void UpdateRange(int L, int R, ll val, int n, int l, int r){
	if(lazy[n]!=0){
		seg[n]+=(r-l+1)*lazy[n];
		if(l!=r){
			lazy[n*2]+=lazy[n];
			lazy[n*2+1]+=lazy[n];
		}
		lazy[n]=0;
	}
	if(R<l || r<L) return;
	if(L<=l && r<=R){
		seg[n]+=(r-l+1)*val;
		if(l!=r){
			lazy[n*2]+=val;
			lazy[n*2+1]+=val;
		}
		return;
	}
	int mid=(l+r)/2;
	UpdateRange(L, R, val, n*2, l, mid);
	UpdateRange(L, R, val, n*2+1, mid+1, r);
	seg[n]=seg[n*2]+seg[n*2+1];
}
ll Query(int L, int R, int n, int l, int r){
	if(lazy[n]!=0){
		seg[n]+=(r-l+1)*lazy[n];
		if(l!=r){
			lazy[n*2]+=lazy[n];
			lazy[n*2+1]+=lazy[n];
		}
		lazy[n]=0;
	}
	if(R<l || r<L) return 0;
	if(L<=l && r<=R) return seg[n];
	int mid=(l+r)/2;
	return seg[n]=Query(L, R, n*2, l, mid)+Query(L, R, n*2+1, mid+1, r);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	for(int i=1; i<=N; ++i){
		ll a; cin>>a;
		UpdateRange(i, i, a, 1, 1, N);
	}
	int M; cin>>M;
	for(int i=0; i<M; ++i){
		int c; cin>>c;
		if(c==1){
			int i1,i2; ll k; cin>>i1>>i2>>k;
			UpdateRange(i1,i2,k,1,1,N);
		}
		else{
			int i1; cin>>i1;
			cout << Query(i1,i1,1,1,N) << '\n';
		}
	}
}