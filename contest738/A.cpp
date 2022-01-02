#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,M; cin>>N>>M;
	int s1,s2; cin>>s1>>s2;
	int e1,e2; cin>>e1>>e2;
	if(N==1 || M==1){
		if(s1==e1 && s2==e2){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	else if((s1+s2)%2 == (e1+e2)%2){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}