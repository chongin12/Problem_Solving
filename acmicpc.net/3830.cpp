#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<int,ll>;
// ll arr[100001]; // 대표값으로부터 떨어진 거리
pii p[100001]; // first : 부모, second : 부모와의 차
pii find(int x){ // 
	if(x==p[x].first) return {x,0};
	pii t=find(p[x].first);
	t.second+=p[x].second;
	return p[x]=t;
}
void unite(int a, int b, ll w){ // a + w == b
	pii A=find(a); // {a의 대표값, a보다 얼마나 가벼운지}
	// cout << "A : " << A.first << ", " << A.second << '\n';
	pii B=find(b); // {b의 대표값, b보다 얼마나 가벼운지}
	// cout << "B : " << B.first << ", " << B.second << '\n';
	// A.second+w가 B.second가 되어야 함.
	// a + w == b
	// A~a + w == B~b
	if(A.first == B.first) return;
	if(A.second+w-B.second>=0){
		p[B.first]={A.first,A.second+w-B.second};
	}
	else{
		p[A.first]={B.first,-(A.second+w-B.second)};
	}
	
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(1){
		int N,M; cin>>N>>M;
		if(N==0 && M==0) break;
		for(int i=1; i<=N; ++i){
			p[i]={i,0};
			// arr[i]=0;
		}
		for(int i=0; i<M; ++i){
			char ch; cin>>ch;
			if(ch=='!'){
				int a,b; ll w; cin>>a>>b>>w;
				unite(a,b,w);
			}
			else{
				for(int i=1; i<=N; ++i){
					// cout << "p["<<i<<"]="<<p[i].first<<", "<<p[i].second<<'\n';
				}
				int a,b; cin>>a>>b;
				pii A=find(a);
				pii B=find(b);
				// cout << "find("<<a<<",0)="<<A.first<<", "<<A.second<<'\n';
				// cout << "find("<<b<<",0)="<<B.first<<", "<<B.second<<'\n';
				if(A.first!=B.first) cout << "UNKNOWN\n";
				else{
					cout << (B.second-A.second) << '\n';
				}
			}
		}
	}
}