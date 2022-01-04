#include <bits/stdc++.h>
using namespace std;
int res[2001];
struct Trie {
	bool fin;
	map<char, Trie*> m;
	Trie(){
		fin=false;
		m.clear();
	}
	void insert(const char* ch){
		if(!*ch){
			fin=true;
			return;
		}
		int now = *ch - 'a';
		if(m.find(now) == m.end()) m[now]=new Trie;
		m[now]->insert(ch+1);
	}
	void find(const char* ch, int idx, bool color){
		if(fin) res[idx]++;
		if(!*ch) return;
		int now = *ch - 'a';
		if(m.find(now) == m.end()) return;
		m[now]->find(ch+1,color ? idx+1:idx-1 , color); 
	}
};
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int C,N; cin>>C>>N;
	Trie * root1 = new Trie;
	Trie * root2 = new Trie;
	for(int i=0; i<C; ++i){
		string str; cin>>str;
		root1->insert(str.c_str()); // str.c_str() 은 string을 char*로 바꿔줌
	}
	for(int i=0; i<N; ++i){
		string str; cin>>str;
		reverse(str.begin(), str.end());
		root2->insert(str.c_str());
	}
	int Q; cin>>Q;
	while(Q--){
		memset(res,0,sizeof(res));
		string str; cin>>str;
		root1->find(str.c_str(), 0, true);
		reverse(str.begin(), str.end());
		root2->find(str.c_str(), str.size(), false); // str.size()로 인덱스 설정 해둬서 만나는 지점의 res값이 2가 됨.
		bool flag=false;
		for(int i=0; i<str.size(); ++i){
			if(res[i]==2){
				flag=true;
				break;
			}
		}
		if(flag){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}