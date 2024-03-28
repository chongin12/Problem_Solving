#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int visit[51];
int main(){
	int N; cin>>N;
	for(int i=0; i<N; ++i){
		int a; cin>>a; v.push_back(a);
	}
	sort(v.begin(), v.end());
	int prev=-2;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(visit[j]) continue;
			if(prev+1==v[j]) continue;
			bool flag=true;
			for(int k=0; k<N; ++k){
				if(visit[k]) continue;
				if(k==j) continue;
				if(v[k]==v[j]) continue;
				if(v[k]!=v[j]+1) flag=false;
			}
			if(flag) continue;
			visit[j]=1;
			cout << v[j] << " ";
			prev=v[j];
			break;
		}
	}
	for(int i=0; i<N; ++i){
		if(!visit[i]) cout << v[i] << " ";
	}
	cout << '\n';
}