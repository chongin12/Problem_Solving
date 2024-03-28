#include <bits/stdc++.h>
using namespace std;
struct node{
	string str;
	vector<int> nxt;
	node(){
		str="";
	}
	node(string str, vector<int> nxt):str(str),nxt(nxt){}
};
vector<node> v;
int num=0;
vector<string> G[1001];
void p(int cnt, string str){
	for(int i=0; i<cnt; ++i){
		cout << "--";
	}
	cout << str << '\n';
}
int main(){
	ios::sync_with_stdio(0);
	int N; cin>>N;
	for(int i=0; i<N; ++i){
		int a; cin>>a;
		for(int j=0; j<a; ++j){
			string str; cin>>str;
			G[i].push_back(str);
		}
	}
	sort(G,G+N);
	v.push_back(node());
	num++;
	for(int i=0; i<N; ++i){
		int cur=0;
		int depth=0;
		bool pass=true;
		for(int j=0; j<G[i].size(); ++j){
			string str=G[i][j];
			for(int k=0; k<v[cur].nxt.size(); ++k){
				if(v[v[cur].nxt[k]].str==str){
					cur=v[cur].nxt[k];
					depth++;
					pass=false;
					break;
				}
				if(k==v[cur].nxt.size()-1){
					pass=true;
				}
			}
			if(pass){
				v[cur].nxt.push_back(num);
				v.push_back(node(str,vector<int>()));
				p(depth, str);
				++depth;
				cur=num;
				++num;
				continue;
			}
			
			
		}
		
	}
}