#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=100000;
ll seg[MN*4+1];
ll arr[MN+1];
ll Update(int idx, int n, int l, int r){
	if(idx<l || r<idx) return seg[n];
	if(l==r) return seg[n]=idx;
	int mid=(l+r)/2;
	ll r1=Update(idx, n*2, l, mid);
	ll r2=Update(idx, n*2+1, mid+1, r);
	if(arr[r1]<=arr[r2]) return seg[n]=r1;
	return seg[n]=r2;
}
ll Query(int L, int R, int n, int l, int r){
	if(r<L || R<l) return -1;
	if(L<=l && r<=R) return seg[n];
	int mid = (l+r)/2;
	ll r1=Query(L,R,n*2,l,mid);
	ll r2=Query(L,R,n*2+1,mid+1,r);
	if(r1==-1) return r2;
	if(r2==-1) return r1;
	if(arr[r1] <= arr[r2]) return r1;
	return r2;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	for(int i=1; i<=N; ++i){
		cin >> arr[i];
		Update(i,1,1,MN);
	}
	int M; cin>>M;
	while(M--){
		int a,b;cin>>a>>b;
		if(a==1){
			ll v; cin>>v;
			arr[b]=v;
			Update(b,1,1,MN);
		}
		else{
			int c;cin>>c;
			cout << Query(b,c,1,1,MN) << '\n';
		}
	}
}