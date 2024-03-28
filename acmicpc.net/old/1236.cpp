#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M; cin>>N>>M;
	int r=0, c=0;
	for(int i=0; i<N; ++i){
		string str; cin>>str; v.push_back(str);
		for(int j=0; j<M; ++j){
			if(str[j]!='.') break;
			if(j==M-1) r++;
		}
	}
	for(int i=0; i<M; ++i){
		for(int j=0; j<N; ++j){
			if(v[j][i]!='.') break;
			if(j==N-1) c++;
		}
	}
	cout << max(r,c) << '\n';
}