#include <bits/stdc++.h>
using namespace std;
vector<string> v;
vector<int> arr[21];
void init(){
	v.clear();
	for(int i=0; i<21; ++i){
		arr[i].clear();
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int cnt=0;
	while(1){
		init();
		cnt++;
		int N; cin>>N;
		if(N==0) break;
		if(cnt!=1) cout << '\n';
		cout << "Group " << cnt << "\n";
		for(int i=0; i<N; ++i){
			string str; cin>>str; v.push_back(str);
			for(int j=1; j<N; ++j){
				char ch; cin>>ch;
				if(ch=='N') arr[i].push_back(i-j);
			}
		}
		bool flag=true;
		for(int i=0; i<N; ++i){
			for(int j=0; j<arr[i].size(); ++j){
				flag=false;
				if(arr[i][j]<0) arr[i][j]+=N;
				cout << v[arr[i][j]] << " was nasty about " << v[i] << '\n';
			}
		}
		if(flag){
			cout << "Nobody was nasty\n";
		}
	}
}