#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void post(int s, int e){ // start부터 end까지
	if(s==e){
		cout << v[s] << '\n';
		return;
	}
	int pos=lower_bound(v.begin()+s+1, v.begin()+e+1, v[s])-v.begin();
	int ls=s+1,le=pos-1;
	int rs=pos,re=e;
	if(ls<=le) post(ls,le);
	if(rs<=re) post(rs,re);
	cout << v[s] << '\n';
}
int main(){
	int a;
	while(cin>>a){
		v.push_back(a);
	}
	post(0,v.size()-1);
}