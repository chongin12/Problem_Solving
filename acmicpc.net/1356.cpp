#include <bits/stdc++.h>
using namespace std;
int main(){
	string str; cin>>str;
	for(int i=1; i<str.size(); ++i){
		int res1=1, res2=1;
		for(int j=0; j<i; ++j){
			res1*=str[j]-'0';
		}
		for(int j=i; j<str.size(); ++j){
			res2*=str[j]-'0';
		}
		if(res1==res2){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}