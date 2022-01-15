#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll dp[1000001]; // dp[i]:Sk(i)의 최소값
bool visit[1000001];
ll nxt[1000001];
ll p[10];
ll calc(ll x){
	if(x<=1000000 && nxt[x]) return nxt[x];
	ll ret=0;
	while(x){
		ret+=p[x%10];
		x/=10;
	}
	if(ret>1000000) return calc(ret);
	return ret;
}
void f(vector<ll> acc){
	ll cur=acc.back();
	if(!dp[cur] && visit[cur]){ // cur부터 시작하는 사이클을 이 사이클의 최솟값으로 모두 채움.
		ll tmp=nxt[cur];
		ll minn=cur;
		while(tmp!=cur){
			minn=min(minn,tmp);
			tmp=nxt[tmp];
		}
		dp[cur]=minn;
		tmp=nxt[cur];
		while(tmp!=cur){
			dp[tmp]=minn;
			tmp=nxt[tmp];
		}
		for(int i=acc.size()-1; i>=0; --i){
			if(!dp[acc[i]]){
				minn=min(minn,acc[i]);
				dp[acc[i]]=minn;
			}
		}
		return;
	}
	if(dp[cur]){
		ll minn=dp[cur];
		for(int i=acc.size()-1; i>=0; --i){
			if(!dp[acc[i]]){
				minn=min(minn,acc[i]);
				dp[acc[i]]=minn;
			}
		}
		return;
	}
	acc.push_back(nxt[cur]);
	visit[cur]=true;
	f(acc);
}
int main(){
	ll A,B,K; cin>>A>>B>>K;
	for(ll i=0; i<10; ++i){
		p[i]=pow(i,K);
		// cout << p[i] << '\n';
	}
	for(ll i=1; i<=1000000; ++i){
		nxt[i]=calc(i);
		// cout << "nxt["<<i<<"]="<< nxt[i] << '\n';
	}
	
	ll res=0;
	for(ll i=A; i<=B; ++i){
		if(!dp[i]) {
			vector<ll> temp;
			temp.push_back(i);
			f(temp);
		} 
		res+=dp[i];
	}
	cout << res << '\n';
	
}