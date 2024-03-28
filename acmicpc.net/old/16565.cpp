#include <bits/stdc++.h>
using namespace std;
int fact[60];
int f(int x, int cnt){
	if(cnt==1) return x;
	int t=f((x*x)%10007,cnt/2);
	int m=1;
	if(cnt%2==1) m=x;
	return (t*m)%10007;
}
int combi(int n, int r){
	return (fact[n]*f((fact[r]*fact[n-r])%10007,10005))%10007;
}
int main(){
	fact[0]=1;
	for(int i=1; i<60; ++i){
		fact[i]=fact[i-1]*i;
		fact[i]%=10007;
	}
	int N; cin>>N;
	int res=0;
	for(int i=1; i<=N/4; ++i){
		if(i%2==1){
			res+=combi(13,i) * combi(52-i*4,N-i*4);
		}
		else{
			res-=combi(13,i) * combi(52-i*4,N-i*4);
		}
		res%=10007;
	}
	if(res<0) res+=10007;
	cout << res%10007 << '\n';
}