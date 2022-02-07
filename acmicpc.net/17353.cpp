#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=100000;
ll seg[MN*4+1];
pair<ll,ll> lazy[MN*4+1]; // lazy에는 별의 시작 개수, 배수를 넣는다.
ll Update(int idx, ll val, int n, int l, int r){
	if(idx<l || r<idx) return 0;
	if(l==r) return seg[n]=val;
	int mid=(l+r)/2;
	return Update(idx, val, n*2, l, mid) + Update(idx, val, n*2+1, mid+1, r);
}
void UpdateRange(int L, int R, int n, int l, int r){
	if(lazy[n].first!=0){
		seg[n]+=(lazy[n].first+lazy[n].first+(r-l)*lazy[n].second)*(r-l+1)/2;
		if(l!=r){
			lazy[n*2].first+=lazy[n].first;
			lazy[n*2].second+=lazy[n].second;
			lazy[n*2+1].first+=((r+l)/2+1-l)*lazy[n].second+lazy[n].first;
			lazy[n*2+1].second+=lazy[n].second;
		}
		lazy[n]={0,0};
	}
	if(R<l || r<L) return;
	if(L<=l && r<=R){
		seg[n]+=(r-l)*(r-l+1)/2+(r-l+1)*(l-L+1);
		if(l!=r){
			lazy[n*2].first+=l-L+1;
			lazy[n*2].second++;
			lazy[n*2+1].first+=(r+l)/2+1-l+l-L+1;
			lazy[n*2+1].second++;
		}
		return;
	}
	int mid=(l+r)/2;
	UpdateRange(L, R, n*2, l, mid);
	UpdateRange(L, R, n*2+1, mid+1, r);
	
	seg[n]=seg[n*2]+seg[n*2+1];
}
ll Query(int L, int R, int n, int l, int r){
	if(lazy[n].first!=0){
		seg[n]+=(lazy[n].first+lazy[n].first+(r-l)*lazy[n].second)*(r-l+1)/2;
		if(l!=r){
			lazy[n*2].first+=lazy[n].first;
			lazy[n*2].second+=lazy[n].second;
			lazy[n*2+1].first+=((r+l)/2+1-l)*lazy[n].second+lazy[n].first;
			lazy[n*2+1].second+=lazy[n].second;
		}
		lazy[n]={0,0};
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
		Update(i, a, 1, 1, N);
	}
	int M; cin>>M;
	for(int i=0; i<M; ++i){
		int c; cin>>c;
		if(c==1){
			int i1,i2; cin>>i1>>i2;
			UpdateRange(i1,i2,1,1,N);
		}
		else{
			int i1; cin>>i1;
			cout << Query(i1,i1,1,1,N) << '\n';
		}
	}
}