#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=100000;
struct node{
	ll b,c,d,idx;
	node(ll b, ll c, ll d, ll idx):b(b),c(c),d(d),idx(idx){}
};
struct upnode{
	ll b,c;
	upnode(ll b, ll c):b(b),c(c){}
};
ll seg[MN*4+1];
ll Update(ll idx, ll val, ll n, ll l, ll r){
	if(idx<l || r<idx) return seg[n];
	if(l==r) return seg[n]=val;
	ll mid=(l+r)/2;
	return seg[n]=Update(idx,val,n*2,l,mid)+Update(idx,val,n*2+1,mid+1,r);
}
ll Query(ll L, ll R, ll n, ll l, ll r){
	if(R<l || r<L) return 0;
	if(L<=l && r<=R) return seg[n];
	ll mid=(l+r)/2;
	return Query(L,R,n*2,l,mid)+Query(L,R,n*2+1,mid+1,r);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll N; cin>>N;
	for(ll i=1; i<=N; ++i){
		ll a; cin>>a;
		Update(i,a,1,1,N);
	}
	ll M; cin>>M;
	vector<upnode> q1;
	vector<node> q2;
	ll cnt=0;
	for(ll i=0; i<M; ++i){
		ll a; cin>>a;
		if(a==1){
			ll b,c; cin>>b>>c;
			q1.push_back(upnode(b,c));
		}
		else{
			ll b,c,d; cin>>b>>c>>d;
			q2.push_back(node(b,c,d,cnt++));
		}
	}
	sort(q2.begin(), q2.end(), [](node a, node b){
		return a.b<b.b;
	});
	ll prev=0;
	ll res[100001]={};
	for(int i=0; i<q2.size(); ++i){
		for(ll j=prev+1; j<=q2[i].b; ++j){
			// cout << "update " << q1[j-1].b << " to " << q1[j-1].c << '\n';
			Update(q1[j-1].b,q1[j-1].c,1,1,N);
		}
		prev=q2[i].b;
		// cout << q2[i].idx << " => " << q2[i].c << " ~ "<<q2[i].d << " : " << Query(q2[i].c,q2[i].d,1,1,N) << '\n';
		res[q2[i].idx]=Query(q2[i].c,q2[i].d,1,1,N);
	}
	for(int i=0; i<cnt; ++i){
		cout << res[i] << '\n';
	}
}