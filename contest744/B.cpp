#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin>>T;
	while(T--){
		ll N; cin>>N;
		bool pass=false;
		ll sqn=sqrt(N);
		if(N%9==0) pass=true;
		if(N%3==2) pass=true;
		if(pass){
			cout << "TAK\n";
		}
		else{
			cout << "NIE\n";
		}
	}
}