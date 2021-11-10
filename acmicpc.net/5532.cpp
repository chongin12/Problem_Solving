#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e; cin>>a>>b>>c>>d>>e;
	cout << a-max((b-1)/d+1,(c-1)/e+1)<<'\n';
}