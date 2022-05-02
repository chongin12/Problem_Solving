#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MN=1000000;
bool sieve[MN+1];
vector<ll> prime;
int main(){
	for(ll i=2; i<=MN; ++i){
		for(ll j=i*i; j<=MN; j+=i){
			sieve[j]=true;
		}
		prime.push_back(i);
	}
	int N; cin>>N;
	for(int i=0; i<N; ++i){
		ll S; cin>>S;
		bool flag=false;
		for(auto it:prime){
			if(S%it==0){
				flag=true;
				break;
			}
		}
		if(flag){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}