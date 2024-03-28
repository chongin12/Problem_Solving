#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	while(N--){
		ll k, c; cin>>k>>c;
		ll r=0;
		while(k){
			if(k%2) r+=1;
			k/=2;
		}
		if((r%2 && c)||(r%2==0 && !c)){
			cout << "Valid\n";
		}
		else{
			cout << "Corrupt\n";
		}
	}
}