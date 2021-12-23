#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> v;
vector<string> temp;
ll fact[20]; // nPr = n! / (n-r)!

ll N,K;
ll f(string str){
	ll m=1;
	ll res=0;
	for(int i=str.size()-1; i>=0; --i){
		ll x=str[i]-'0';
		res=(res+(x%K)*m)%K;
		m=(m*10)%K;
	}
	return res;
}
int main(){
	cin>>N;
	for(int i=0; i<N; ++i){
		string str; cin>>str;
		temp.push_back(str);
	}
	cin>>K;
	for(int i=0; i<N; ++i){
		v.push_back(f(temp[i]));
		cout << v[i] << '\n';
	}
	fact[0]=1;
	for(ll i=1; i<=15; ++i){
		fact[i]=fact[i-1]*i;
	}
	/*
	이제 할 것은?
	우선 순열의 개수를 센다. (fact 사용)
	구성된 v들로 순열을 구성한다. mod k로 나눠 떨어지는지 하나하나 확인.
	정답 출력.
	*/
}