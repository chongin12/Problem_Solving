#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=500000;

ll seg[MN*4+1];
ll id[MN*2+1];
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
	return seg[n]=Update(idx,val,n*2,l,mid)+Update(idx,val,n*2+1,mid+1,r);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	for(ll i=1; i<=N; i+=1){
		int a; cin>>a;
		id[a]=i;
	}
	ll res=0;
	for(int i=1; i<=N; ++i){
		int a; cin>>a;
		ll cur=id[a];
		res+=Query(cur+1,MN,1,1,MN);
		Update(cur,1,1,1,MN);
	}
	cout << res << '\n';
}