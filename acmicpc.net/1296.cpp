#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string x; cin>>x;
	int N; cin>>N;
	string res=""; int resN=-1;
	for(int i=0; i<N; ++i){
		string str; cin>>str;
		int l=0, o=0, v=0, e=0;
		for(auto it:x){
			if(it=='L') l++;
			if(it=='O') o++;
			if(it=='V') v++;
			if(it=='E') e++;
		}
		for(auto it:str){
			if(it=='L') l++;
			if(it=='O') o++;
			if(it=='V') v++;
			if(it=='E') e++;
		}
		int k=((l+o)*(l+v)*(l+e)*(o+v)*(o+e)*(v+e))%100;
		if(resN<k){
			resN=k;
			res=str;
		}
		else if(resN==k){
			res=min(res,str);
		}
	}
	cout << res << '\n';
}