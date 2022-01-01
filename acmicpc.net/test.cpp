/*
확장 유클리드 알고리즘
GCD(a,b)=d일 때,
ax+by=d를 만족하는 x,y를 찾아야 한다.
*/
#include <bits/stdc++.h>
using namespace std;
pair<int,int> EEA(int a, int b){
	int r0=a, r1=b;
	int s0=1, s1=0;
	int t0=0, t1=1;
	while(r1){
		int q=r0/r1;
		int r2=r0-r1*q;
		r0=r1;
		r1=r2;
		int s2=s0-s1*q;
		s0=s1;
		s1=s2;
		int t2=t0-t1*q;
		t0=t1;
		t1=t2;
	}
	cout << "r0 : " << r0 <<", r1 : "<<r1<<'\n';
	cout << "s0 : " << s0 <<", s1 : "<<s1<<'\n';
	cout << "t0 : " << t0 <<", t1 : "<<t1<<'\n';
	cout << "ax+by=d => "<<a<<"*"<<s0<<"+"<<b<<"*"<<t0<<"="<<r0<<'\n';
	return {s0,t0};
}
int main(){
	int a,b; cin>>a>>b;
	pair<int,int> ans=EEA(a,b);
}