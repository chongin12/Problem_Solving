#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long int;
using pii=pair<ll,ll>;
vector<pii> v;
struct cmp{
	bool operator()(pii a, pii b){
		if(a.y==b.y) return a.x<b.x;
		return a.y<b.y;
	}
};
bool comp(pii a, pii b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0; i<n; ++i){
		ll a,b; cin>>a>>b;
		v.push_back({min(a,b),max(a,b)});
	}
	sort(v.begin(), v.end(), comp);
	ll d; cin>>d;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	ll res=0;
	ll cnt=0;
	for(int i=0; i<v.size(); ++i){
		pii now=v[i];
		if(now.y-now.x>d) continue;
		while(!pq.empty()){
			pii top=pq.top();
			if(top.x+d>=now.y){
				break;
			}
			else{
				pq.pop();
				cnt--;
			}
		}
		pq.push(now);
		cnt++;
		res=max(res,cnt);
	}
	cout << res << '\n';
}