#include <bits/stdc++.h>
using namespace std;
vector<int> getFail(const string &p){
	int m = p.size();
	vector<int> fail(m);
	for(int i=1, j=0; i<m; ++i){
		while(j>0 && p[i]!=p[j]) j=fail[j-1];
		if(p[i]==p[j]) fail[i]=++j;
	}
	return fail;
}
vector<int> KMP(const string &s, const string &p){
	int n=s.size();
	int m=p.size();
	vector<int> fail = getFail(p), res;
	for(int i=0, j=0; i<n; ++i){
		while(j>0 && s[i]!=p[j]) j=fail[j-1];
		if(s[i]==p[j]){
			if(j==m-1) res.push_back(i-m+1), j=fail[j];
			else j++;
		}
	}
	return res;
}
int main(){
	string T, P;
	getline(cin,T);
	getline(cin,P);
	int n=T.size();
	int m=P.size();
	vector<int> res = KMP(T, P);
	cout << res.size() << '\n';
	for(auto it:res){
		cout << it+1 << " ";
	}
	cout << '\n';
}