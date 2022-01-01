#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int N,G,K;
struct node{
	ll s,l,o;
	node(ll s, ll l, ll o):s(s),l(l),o(o){}
};
vector<node> v;
ll f(ll x){
	ll t=0;
	priority_queue<ll> pq; // 세균 수
	ll s;
	for(int i=0; i<v.size(); ++i){
		s=v[i].s*max(1LL,x-v[i].l);
		t+=s;
		if(v[i].o==1) pq.push(s);
	}
	ll cnt=0;
	while(!pq.empty() && cnt<K){
		ll top=pq.top(); pq.pop();
		t-=top;
		cnt+=1;
	}
	return t;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N>>G>>K;
	for(int i=0; i<N; ++i){
		ll s,l,o; cin>>s>>l>>o;
		v.push_back(node(s,l,o));
	}
	sort(v.begin(), v.end(), [](node a, node b){return a.s<b.s;});
	ll lo=1, hi=2e9+1; 
	while(lo<hi-1){
		ll mid=(lo+hi)/2;
		if(f(mid)>G) hi=mid;
		else lo=mid;
	}
	cout << lo << '\n';
}