#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=200000;
vector<int> G[MN+1];
int p[MN+1];
int id[MN+1]; // A도시의 id를 담는다.
ll level[MN+1]; // A도시의 level을 담는다.
ll water[MN+1]; // A도시의 지목 횟수를 담는다.
int children[MN+1]; // A도시의 모든 자식 개수를 담는다. 본인 미포함.
ll seg[MN*4+1];
int cnt=0;
int dfs(int x, int prev, ll lev){
	id[x]=++cnt;
	level[x]=lev;
	for(auto nxt:G[x]){
		if(nxt==prev) continue;
		p[nxt]=x;
		children[x]+=dfs(nxt,x,lev+1);
	}
	return children[x]+1;
}
ll Update(int idx, ll val, int n, int l, int r){
	if(idx<l || r<idx) return seg[n];
	if(l==r) return seg[n]=val;
	int mid=(l+r)/2;
	return seg[n]=Update(idx, val, n*2, l, mid)+Update(idx, val, n*2+1, mid+1, r);
}
ll Query(int L, int R, int n, int l, int r){
	if(R<l || r<L) return 0;
	if(L<=l && r<=R) return seg[n];
	int mid=(l+r)/2;
	return Query(L,R,n*2,l,mid)+Query(L,R,n*2+1,mid+1,r);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,C; cin>>N>>C;
	for(int i=0; i<N-1; ++i){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(C,0,1);
	int q; cin>>q;
	while(q--){
		int ch,A; cin>>ch>>A;
		if(ch==1){
			water[A]++;
			Update(id[A],water[A],1,1,N);
		}
		else{
			// A에서 부모로 올라간 후, 부모에서 해당 자식을 찾는다.
			// 해당 자식의 id(id1)와 그 다음 자식의 id(id2)를 찾는다.
			// id1~id2-1의 쿼리*level[A]을 출력한다.
			int id1=id[A], id2=id[A]+children[A];
			cout << level[A]*Query(id1,id2,1,1,N) << '\n';
		}
	}
}