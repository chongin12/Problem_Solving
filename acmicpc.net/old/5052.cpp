#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin>>T;
	while(T--){
		vector<string> v;
		int n; cin>>n;
		for(int i=0; i<n; ++i){
			string str; cin>>str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());
		// for(auto it:v){
		// 	cout << it << '\n';
		// }
		bool goal=true;
		for(int i=1; i<v.size(); ++i){
			bool pass=true;
			for(int j=0; j<v[i-1].size() && j<v[i].size(); ++j){
				if(v[i-1][j]!=v[i][j]) {
					pass=false;
					break;
				}
			}
			if(pass) goal=false;
		}
		if(goal){
			cout << "YES" << '\n';
		}
		else{
			cout << "NO" << '\n';
		}
	}
}