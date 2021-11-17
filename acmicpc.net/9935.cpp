#include <bits/stdc++.h>
using namespace std;
string str;
string bomb;
vector<char> r;
int bl;
void check(){
	int rl=r.size();
	bool pass=true;
	for(int i=1; i<=bl; ++i){
		if(rl-i<0) {
			pass=false;
			break;
		}
		if(r[rl-i] != bomb[bl-i]){
			pass=false;
			break;
		}
	}
	if(pass){
		for(int i=0; i<bl; ++i){
			r.pop_back();
		}
		check();
	}
	return;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>str;
	cin>>bomb;
	bl=bomb.length();
	for(auto i :str){
		r.push_back(i);
		check();
	}
	if(r.size()==0){
		cout << "FRULA\n";
	}
	else{
		for(auto it : r){
			cout << it;
		}
		cout << '\n';
	}
}