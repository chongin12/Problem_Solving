#include <bits/stdc++.h>
using namespace std;
bool sieve[100000];
vector<int> v;
int main(){
	int a; cin>>a;
	for(int i=2; i*i<100000; ++i){
		for(int j=i*i; j<100000; j+=i){
			sieve[j]=true;
		}
	} 
	for(int i=2; i<100000; ++i){
		if(!sieve[i]) v.push_back(i);
	}
	for(int i=1; i<v.size(); ++i){
		if(v[i-1]*v[i]>a){
			cout << v[i-1]*v[i] << '\n';
			return 0;
		}
	}
}