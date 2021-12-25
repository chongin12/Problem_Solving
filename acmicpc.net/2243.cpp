#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=1000000;

int seg[MN*4+1];
int arr[MN+1];
int Update(int idx, int val, int n, int l, int r){
	if(r<idx || idx<l) return seg[n];
	if(l==r) return seg[n]=val;
	int mid=(l+r)/2;
	return seg[n]=Update(idx,val,n*2,l,mid)+Update(idx,val,n*2+1,mid+1,r);
}
int Query(int L, int R, int n, int l, int r){
	if(r<L || R<l) return 0;
	if(L<=l && r<=R) return seg[n];
	int mid=(l+r)/2;
	return Query(L,R,n*2,l,mid)+Query(L,R,n*2+1,mid+1,r);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0; i<n; ++i){
		int a; cin>>a;
		if(a==1){
			int b; cin>>b;
			int l=0, r=MN+1;
			while(l<r-1){
				int mid=(l+r)/2; // Query(1~mid)와 b를 비교
				int q=Query(1,mid,1,1,MN);
				// cout << "mid : " << mid << ", q : " << q << '\n';
				if(q < b){
					l=mid;
				}
				else{
					r=mid;
				}
			}
			// l->r 넘어갈 때 변화함. 즉 r의 위치에서 1을 빼야 함.
			// cout << "l : " << l << ", r : " << r << '\n';
			cout << r << '\n';
			arr[r]-=1;
			Update(r,arr[r],1,1,MN);
		}
		else{
			int b,c; cin>>b>>c;
			arr[b]+=c;
			Update(b,arr[b],1,1,MN);
		}
	}
}