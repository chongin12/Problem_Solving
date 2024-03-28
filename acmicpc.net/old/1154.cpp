#include <bits/stdc++.h>
using namespace std;
vector<int> G[1001];
int arr[1001][1001];
int p[1001];
void init(){
	for(int i=0; i<1001; ++i){
		p[i]=i;
	}
}
int find(int x){
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}
void unite(int a, int b){
	int A=find(a);
	int B=find(b);
	if(A==1) p[B]=A;
	else if(B==1) p[A]=B;
	else p[A]=B;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin>>N;
	init();
	while(1){
		int a,b; cin>>a>>b;
		if(a==-1) break;
		G[a].push_back(b);
		G[b].push_back(a);
		arr[a][b]=1;
		arr[b][a]=1;
	}
	vector<int> v;
	for(int i=1; i<=N; ++i){
		v.clear();
		for(int j=1; j<=N; ++j){
			if(i==j) continue;
			if(!arr[i][j]) v.push_back(j);
		}
		for(int j=1; j<v.size(); ++j){
			unite(v[j-1], v[j]);
		}
	}
	int visit[1001]={0, };
	for(int i=1; i<=N; ++i){
		visit[find(i)]++;
	}
	v.clear();
	int cnt=0;
	for(int i=1; i<=N; ++i){
		if(visit[i]==1){
			v.push_back(i);
		}
		else if(visit[i]>1){
			cnt++;
		}
	}
	if(!v.empty()) cnt++;
	if(cnt>2){
		cout << "-1\n";
		return 0;
	}
	for(int i=1; i<v.size(); ++i){
		unite(v[i-1],v[i]);
	}
	vector<int> res1;
	vector<int> res2;
	for(int i=1; i<=N; ++i){
		if(find(i)==1) res1.push_back(i);
		else res2.push_back(i);
	}
	for(int i=0; i<res1.size(); ++i){
		for(int j=0; j<i; ++j){
			if(!arr[res1[i]][res1[j]]){
				cout << "-1\n";
				return 0;
			}
		}
	}
	for(int i=0; i<res2.size(); ++i){
		for(int j=0; j<i; ++j){
			if(!arr[res2[i]][res2[j]]){
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << "1\n";
	sort(res1.begin(), res1.end());
	sort(res2.begin(), res2.end());
	for(auto it:res1) cout << it << " ";
	cout << "-1\n";
	for(auto it:res2) cout << it << " ";
	cout << "-1\n";
}