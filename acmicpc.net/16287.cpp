#include <bits/stdc++.h>
using namespace std;
bool chk[800000];
vector<int> v;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int w, n; cin>>w>>n;
	for(int i=0; i<n; ++i){
		int a; cin>>a;
		v.push_back(a);
	}
	for(int i=0; i<n-1; ++i){
		for(int j=i+1; j<n; ++j){
			if(v[i]+v[j]<w && chk[w-v[i]-v[j]]){
				cout << "YES" << '\n';
				return 0;
			}
		}
		for(int j=0; j<i; ++j){ // 중복되면 안되지 for문 다음에 위치.
			if(w>v[i]+v[j]) chk[v[i]+v[j]]=true;
		}
	}
	cout << "NO" << '\n';
}