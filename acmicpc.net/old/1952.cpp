#include <bits/stdc++.h>
using namespace std;
int main(){
	int M,N; cin>>M>>N;
	bool flag=true;
	int res=0;
	M--;
	while(M && N){
		res++;
		if(flag) N--;
		else M--;
		flag=!flag;
	}
	cout << res << '\n';
}