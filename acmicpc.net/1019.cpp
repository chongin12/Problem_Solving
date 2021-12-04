#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll dp[20];
ll N;
ll res[10];
ll jari(ll x){
	ll t=x;
	ll ret=0;
	while(t!=0){
		ret+=1;
		t/=10;
	}
	return ret;
}
ll fNum(ll x){ // front number
	ll t=x;
	while(t/10!=0){
		t/=10;
	}
	return t;
}
ll solve(ll x, ll ja){ // return : 
	//cout << "x : " << x << ", ja : " << ja << '\n';
	ll fn=fNum(x);
	if(jari(x)!=ja){
		fn=0;
	}
	if(ja==1){
		for(ll i=0; i<=fn; ++i){
			res[i]+=1;
		}
		//cout << "return : " << fn+1 << '\n';
		return fn+1;
	}
	if(fn==0) {
		res[0]+=solve(x,ja-1);
	}
	else {
		for(ll i=0; i<fn; ++i){
			for(int j=0; j<10; ++j){
				res[j]+=dp[ja-1];
			}
			res[i]+=pow(10,ja-1);
		}
		ll madeNum=x-fn*pow(10,ja-1);
		res[fn]+=solve(madeNum,ja-1);
	}
	//cout << x << "일 때 return : " << x+1 << '\n';
	return x+1;
}
int main(){
	cin>>N;
	ll j=1;
	dp[0]=0;
	for(ll i=1; i<=11; ++i){
		dp[i]=i*j;
		j*=10;
	}
	ll ja=jari(N);
	solve(N, ja);
	for(ll i=ja-1; i>0; --i){
		res[0]-=pow(10,i);
	}
	res[0]-=1;
	for(int i=0; i<10; ++i){
		cout << res[i] << " ";
	}
	cout << '\n';
}