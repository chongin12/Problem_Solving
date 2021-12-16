#include <bits/stdc++.h>
using namespace std;
int p[500001];
int find(int x){
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}
bool unite(int a, int b){
	int A=find(a);
	int B=find(b);
	if(A==B) return true;
	p[B]=A;
	return false;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	for(int i=0; i<n; ++i){
		p[i]=i;
	}
	for(int i=0; i<m; ++i){
		int a,b; cin>>a>>b;
		if(unite(a,b)){
			cout << i+1 << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
}