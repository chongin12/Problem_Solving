#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll visit[10];
ll N,d;
ll ans;
void f(ll cnt){
	if(cnt==d){
		ll temp[10]={0,};
		for(ll i=0; i<d; ++i){
			// cout << "visit["<<i<<"]="<<visit[i]<<'\n';
			temp[visit[i]]=i;
		}
		if(temp[d-1]==0) return;
		ll t=1;
		ll res=0;
		for(ll i=0; i<d; ++i){
			res+=t*temp[i];
			t*=d;
		}
		if(res>N && ans>res) ans=res;
		return;
	}
	for(int i=0; i<d; ++i){
		if(visit[i]==-1){
			visit[i]=cnt;
			f(cnt+1);
			visit[i]=-1;
		}
	}
	return;
}
int main(){
	
	cin>>N>>d;
	ans=987654321987654321;
	for(int i=0; i<d; ++i){
		visit[i]=-1;
	}
	f(0);
	if(ans==987654321987654321) cout << "-1\n";
	else cout << ans << '\n';
}