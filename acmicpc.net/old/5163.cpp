#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin>>T;
	int cnt=0;
	while(T--){
		cnt++;
		int a; double k; cin>>a>>k;
		k*=1000;
		double res=0;
		for(int i=0; i<a; ++i){
			double b; cin>>b;
			res+=M_PI*4*b*b*b/3;
		}
		if(cnt!=1) cout << '\n';
		cout << "Data Set "<<cnt<<":\n";
		if(k<=res){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}