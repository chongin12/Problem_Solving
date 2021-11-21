/*
dp[i]=i를 마지막으로 하는 연속한 소수들의 합이 n이 되는 경우의 수
*/
#include <bits/stdc++.h>
using namespace std;
const int PMAX=4e6;
bool sieve[PMAX+1];
vector<int> p;
vector<int> psum;
int main(){
	for(int i=2; i*i<=PMAX; ++i){
		for(int j=i*i; j<=PMAX; j+=i){
			sieve[j]=true;
		}
	}
	p.push_back(2);
	psum.push_back(0);
	psum.push_back(2);
	for(int i=3; i<=PMAX; ++i){
		if(!sieve[i]) {
			p.push_back(i);
			psum.push_back(psum.back()+i);
		}
	}
	int n; cin>>n;
	int res=0;
	for(int i=1; i<psum.size(); ++i){
		for(int j=i-1; j>=0; --j){
			if(psum[i]-psum[j]>n){
				break;
			}
			if(psum[i]-psum[j]==n){
				++res;
			}
		}
	}
	cout << res << '\n';
}