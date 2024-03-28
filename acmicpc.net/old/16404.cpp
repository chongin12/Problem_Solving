#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=100000;
ll seg[MN*4+1], lazy[MN*4+1];
pair<int,int> sub[MN+1]; // i의 부사수는(자신포함) .first ~ .second이다.
int idx[MN+1]; // 직원i의 인덱스를 갖고 있음.
int id=0;
vector<int> G[MN+1];
ll Update(int idx, ll val, int n, int l, int r){
	if(idx<l || r<idx) return seg[n];
	if(l==r) return seg[n]=val;
	int mid=(l+r)/2;
	return Update(idx, val, n*2, l, mid) + Update(idx, val, n*2+1, mid+1, r);
}
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
	if(r<L || R<l) return 0;
	if(L<=l && r<=R) return seg[n];
	int mid=(l+r)/2;
	return Query(L, R, n*2, l, mid) + Query(L, R, n*2+1, mid+1, r);
}
pair<int,int> dfs(int x){//sub배열과 idx배열을 완성한다.
	if(idx[x]==0) idx[x]=++id;
	int ret1=idx[x], ret2=idx[x];
	if(G[x].size()!=0) {
		for(int i=0; i<G[x].size(); ++i){
			int nxt=G[x][i];
			pair<int,int> temp=dfs(nxt);
			ret1=min(ret1,temp.first);
			ret2=max(ret2,temp.second);
		}
	}
	return sub[idx[x]]={ret1,ret2};
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M; cin>>N>>M;
	int root;
	for(int i=1; i<=N; ++i){
		ll a; cin>>a;
		if(a==-1) root=i;
		else G[a].push_back(i);
	}
	idx[root]=++id;
	sub[idx[root]]=dfs(root);
	// for(int i=1; i<=N; ++i){
	// 	cout << "idx["<<i<<"]="<<idx[i]<<'\n';
	// }
	// for(int i=1; i<=N; ++i){
	// 	cout << "i : " << i << ", sub[i] : " << sub[i].first << ", " << sub[i].second << '\n';
	// }
	//직원i의 손실? -> sub[idx[i]]구간에 손실 적용.
	//직원i의 잔고? -> idx[i]~idx[i]구간합
	for(int i=0; i<M; ++i){
		int c; cin>>c;
		if(c==1){
			int em; ll w; cin>>em>>w;
			UpdateRange(sub[idx[em]].first, sub[idx[em]].second, w, 1, 1, N);
		}
		else{
			int em; cin>>em;
			cout << Query(idx[em], idx[em], 1, 1, N) << '\n';
		}
	}
}