#include <bits/stdc++.h>
using namespace std;
int res;
vector<string> v;
void f(int L, int R, int k, int cnt){
	if(L>R) return;
	if(L==R) {
		if(cnt==0) cnt=1;
		res+=cnt;
		return;
	}
	int prev=L;
	for(int i=L+1; i<=R; ++i){
		if(v[i-1].size()<=k){
			f(prev,i-1,k+1,cnt);
			prev=i;
		}
		else if(v[i].size()<=k){
			f(prev,i-1,k+1,cnt+1);
			res+=cnt;
			prev=i+1;
			i++;
		}
		else if(v[i][k]!=v[i-1][k]){
			f(prev,i-1,k+1,cnt+1);
			prev=i;
		}
	}
	if(prev==L){
		if(cnt==0) cnt=1;
		f(prev,R,k+1,cnt);
	}
	else {
		f(prev,R,k+1,cnt+1);
	}
}
void init(){
	v.clear();
	res=0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed;
	cout.precision(2);
	while(1){
		init();
		int N; cin>>N;
		if(cin.eof()) return 0;
		for(int i=0; i<N; ++i){
			string str; cin>>str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());
		f(0,v.size()-1,0,0);
		cout << (double)res/N << '\n';
	}
}