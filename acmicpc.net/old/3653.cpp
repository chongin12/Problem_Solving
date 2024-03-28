#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=200000;
const int INF=987654321;
ll seg[MN*4+1];
ll arr[MN+1];
ll Query(int L, int R, int n, int l, int r){
	if(r<L || R<l) return 0;
	if(L<=l && r<=R) return seg[n];
	int mid=(l+r)/2;
	return Query(L,R,n*2,l,mid)+Query(L,R,n*2+1,mid+1,r);
}
ll Update(int idx, ll val, int n, int l, int r){
	if(idx<l || r<idx) return seg[n];
	if(l==r) return seg[n]=val;
	int mid=(l+r)/2;
	return seg[n]=Update(idx,val,n*2,l,mid) + Update(idx,val,n*2+1,mid+1,r);
}
void init(){
	for(int i=0; i<MN+1; ++i){
		arr[i]=0;
		
	}
	for(int i=0; i<MN*4+1; ++i){
		seg[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin>>T;
	while(T--){
		init();
		int n, m; cin>>n>>m;
		int k=0;
		for(int i=n; i>=1; --i){
			arr[i]=++k;
			Update(arr[i],1,1,1,MN);
		}
		for(int i=0; i<m; ++i){
			int a; cin>>a;
			ll res= Query(arr[a]+1,k,1,1,MN);
			cout << res << " ";
			Update(arr[a],0,1,1,MN);
			arr[a]=++k;
			Update(arr[a],1,1,1,MN);
		}
		cout << '\n';
	}
}