#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
	ll a,b;cin>>a>>b;
	queue<pair<ll,ll> > q;
	q.push({a,1});
	while(!q.empty()){
		pair<ll,ll> f=q.front();
		ll cur=f.first;
		q.pop();
		if(cur==b){
			cout << f.second << '\n';
			return 0;
		}
		else if(cur>b) continue;
		q.push({cur*2,f.second+1});
		q.push({cur*10+1,f.second+1});
	}
	cout << -1 << '\n';
}
//1000000000