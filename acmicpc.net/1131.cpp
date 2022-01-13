#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll A,B,K;
ll dp[1000100];
ll visit[1000100];
ll p[10];
ll calc(ll x){
	ll ret=0;
	while(x){
		ret+=p[x%10];
		x/=10;
	}
	if(ret>1000000) return calc(ret);
	return ret;
}
ll f(ll x){
	if(dp[x]) return dp[x];
	ll minn=x;
	/*
	현재 돌고있을 때 중복되어 visit를 만난게 아닌,
	이미 사이클이 한번 돌았던 곳의 visit를 만났다면?
	내가 지나간 곳을 체크해줄 필요가 있음.
	*/
	bool chk[1000001];
	if(visit[x]){
		ll tmp=x;
		while(!visit[tmp]){
			visit[tmp]=1;
			minn=min(minn, tmp);
			tmp=calc(tmp);
		}
		dp[x]=minn;
		ll tt=tmp;
		tmp=calc(tmp);
		while(tmp!=tt){
			dp[tmp]=minn;
			tmp=calc(tmp);
		}
		dp[tt]=minn;
		return dp[x];
	}
	visit[x]=1;
	return dp[x]=min(minn,f(calc(x)));
}
int main(){
	cin>>A>>B>>K;
	for(int i=0; i<10; ++i){
		p[i]=pow(i,K);
	}
	for(int i=1; i<=1000000; ++i){
		if(!dp[i]) dp[i]=f(i);
		// cout << "dp["<<i<<"]="<<dp[i]<<'\n';
	}
	// cout << dp[24887]<<'\n';
	ll res=0;
	for(int i=A; i<=B; ++i){
		res+=dp[i];
		// cout << "dp["<<i<<"]="<<dp[i]<<'\n';
	}
	cout << res << '\n';
}