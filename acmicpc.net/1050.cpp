#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
map<string, ll> m;
vector<string> v;
vector<vector<pair<ll,string> > > ex(51);
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M; cin>>N>>M;
	for(int i=0; i<N; ++i){
		string str; cin>>str;
		ll a; cin>>a;
		m[str]=a;
	}
	for(int i=0; i<M; ++i){
		string str; cin>>str;
		int idx=0;
		string s="";
		while(str[idx]!='='){
			s+=str[idx++];
		}
		ex[i].push_back({0,s});
		if(m.find(s)==m.end()){
			m[s]=-1;
		}
		while(1){
			string temp="";
			idx++;
			if(idx>=str.size()) break;
			ll coef=str[idx++]-'0';
			while(idx<str.size() && str[idx]!='+'){
				temp+=str[idx++];
			}
			ex[i].push_back({coef,temp});
			if(m.find(temp)==m.end()){
				m[temp]=-1;
			}
		}
	}
	for(int i=0; i<M; ++i){
		for(int j=0; j<M; ++j){
			ll cnt=0;
			string goal=ex[j][0].second;
			bool flag=true;
			for(int k=1; k<ex[j].size(); ++k){
				if(m[ex[j][k].second]==-1){
					flag=false;
					break;
				}
				cnt+=m[ex[j][k].second]*ex[j][k].first;
				if(cnt>1000000000) cnt=1000000001;
			}
			if(flag){
				if(m[goal]==-1) m[goal]=cnt;
				else m[goal]=min(m[goal],cnt);
			}
		}
	}
	if(m.find("LOVE")==m.end() || m["LOVE"]==-1){
		cout << "-1\n";
	}
	else{
		cout << m["LOVE"] << '\n';
	}
}