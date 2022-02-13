#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	set<int> s;
	for(int i=0; i<N; ++i){
		int a; cin>>a;
		s.insert(a);
	}
	cout << N-s.size() << '\n';
}