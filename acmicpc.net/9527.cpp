#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll dnc(ll a, ll b, ll k){ // a~b
	//a~a+k-1 , a+k~b로 쪼개기.
	if(a>=b) {
		return 0;
	}
	if(a==0 && b==k*2-1){
		ll cnt=0;
		ll temp=b;
		while(temp>0){cnt++;temp/=2;}
		return cnt*k;
	}
	if(a+k-1>b){
		return dnc(a,b,k/2);
	}
	return dnc(a,a+k-1,k/2)+dnc(a,b-k,k/2)+b-(a+k)+1;
}
int main(){
	ll A,B; cin>>A>>B;
	ll k1=1, k2=1;
	A--;
	for(k1=1; k1<=A; k1*=2){}
	for(k2=1; k2<=B; k2*=2){}
	cout << dnc(0,B,k2/2) - dnc(0,A,k1/2) << '\n';
}