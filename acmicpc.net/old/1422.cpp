#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int> > v;
bool comp(pair<string, int> x, pair<string, int> y){
	int xl=x.first.size();
	int yl=y.first.size();
	string xtemp=x.first+y.first;
	string ytemp=y.first+x.first;
	for(int i=0; i<xl+yl; ++i){
		if(xtemp[i]!=ytemp[i]){
			return xtemp[i]>ytemp[i];
		}
	}
	return xl<yl;
}
int main(){
	int K,N; cin>>K>>N;
	int maxlen=-1;
	for(int i=0; i<K; ++i){
		string str; cin>>str; v.push_back({str,i});
		maxlen=max(maxlen, (int)str.size());
	}
	vector<pair<string,int> > temp;
	for(int i=0; i<v.size(); ++i){
		if(v[i].first.size()==maxlen){
			temp.push_back(v[i]);
		}
	}
	sort(v.begin(), v.end(), comp);
	sort(temp.begin(), temp.end(), comp);
	int flag=temp[0].second;
	for(int i=0; i<v.size(); ++i){
		if(v[i].second==flag){
			for(int j=0; j<N-K+1; ++j){
				cout << v[i].first;
			}
		}
		else{
			cout << v[i].first;
		}
	}
	cout << '\n';
}