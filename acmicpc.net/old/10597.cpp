#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
string str; 
vector<int> v;
int filled[51];
int flag=false;
void f(int idx){
	if(flag) return;
	if(idx==str.size()){
		int zeroocc=0;
		for(int i=1; i<51; ++i){
			if(filled[i]==0) zeroocc=1;
			else if(filled[i]==1 && zeroocc==1) return;
		}
		for(auto it:v) cout << it << ' ';
		cout << '\n';
		flag=true;
		return;
	}
	int k = str[idx]-'0';
	if(k==0) return;
	if(!filled[k]) {
		filled[k]=1;
		v.push_back(k);
		f(idx+1);
		v.pop_back();
		filled[k]=0;
	}
	if(flag) return;
	if(idx==str.size()-1) return;
	k = k*10 + str[idx+1]-'0';
	if(k<=50 && !filled[k]) {
		filled[k]=1;
		v.push_back(k);
		f(idx+2);
		v.pop_back();
		filled[k]=0;
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>str;
	f(0);
}
