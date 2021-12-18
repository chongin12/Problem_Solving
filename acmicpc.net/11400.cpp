#include <bits/stdc++.h>
using namespace std;

vector<int> G[100001];
int visit[100001];
vector<pair<int,int> > cut;
int k;
int dfs(int x, int prev){
	visit[x]=++k;
	int ret=visit[x];
	for(int i=0; i<G[x].size(); ++i){
		int nxt=G[x][i];
		if(nxt==prev) continue;
		if(visit[nxt]){
			ret=min(ret,visit[nxt]);
			continue;
		}
		int minvisit=dfs(nxt,x);
		if(minvisit>visit[x]){
			cut.push_back({min(x,nxt),max(x,nxt)});
		}
		ret=min(ret,minvisit);
	}
	return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int V,E;cin>>V>>E;
	for(int i=0; i<E; ++i){
		int a,b;cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1; i<=V; ++i){
		if(!visit[i]) dfs(i,0);
	}
	sort(cut.begin(), cut.end());
	cout << cut.size() << '\n';
	for(auto it:cut){
		cout << it.first << " " << it.second << '\n';
	}
}