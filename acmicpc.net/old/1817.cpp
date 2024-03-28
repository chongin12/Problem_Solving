#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,M; cin>>N>>M;
	vector<int> v;
	for(int i=0; i<N; ++i){
		int a; cin>>a;
		v.push_back(a);
	}
	
	int res=0;
	int cnt=0;
	for(int i=N-1; i>=0; --i){
		if(cnt+v[i]>M) {
			res++;
			cnt=v[i];
		}
		else cnt+=v[i];
	}
	if(cnt) res++;
	cout << res << '\n';
}