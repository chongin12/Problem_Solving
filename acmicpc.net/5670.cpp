#include <bits/stdc++.h>
using namespace std;
int res;
vector<string> v;
void f(int L, int R, int k, int cnt){
	// L : 가장 왼쪽, R : 가장 오른쪽, k : 앞에 몇개가 똑같은지, cnt : 횟수 누적
	// cout << "L : " << L << ", R : " << R << ", k : " << k << ", cnt : " << cnt << '\n';
	if(L>R) return;
	if(L==R) {
		if(cnt==0) cnt=1;
		// cout << "res+="<<cnt<<'\n';
		res+=cnt;
		return;
	}
	int prev=L;
	for(int i=L+1; i<=R; ++i){
		//k번째 문자가 같은 것 끼리 f로 묶어준다.
		if(v[i-1].size()<=k){
			f(prev,i-1,k+1,cnt);
			prev=i;
		}
		else if(v[i].size()<=k){
			f(prev,i-1,k+1,cnt+1);
			res+=cnt;
			// cout << "res+="<<cnt<<'\n';
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
	while(1){
		init();
		int N; cin>>N;
		if(cin.eof()) return 0;
		for(int i=0; i<N; ++i){
			string str; cin>>str;
			v.push_back(str);
		}
		sort(v.begin(), v.end());
		// for(auto it:v){
		// 	cout << it << '\n';
		// }
		f(0,v.size()-1,0,0);
		// cout << "res : " << res << '\n';
		cout << fixed;
		cout.precision(2);
		cout << (double)res/N << '\n';
	}
}
/*

*/