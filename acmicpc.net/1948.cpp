#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF = 987654321;
vector<pii> G[10001];
int visit1[10001];
vector<int> topo;
int dist[10001];
vector<int> revG[10001];
int visit2[10001];
int n,m;
int S,E;
int res;
void dfs1(int x){
	if(visit1[x]) return;
	// cout << "x : " << x << '\n';
	visit1[x]=1;
	for(int i=0; i<G[x].size(); ++i){
		dfs1(G[x][i].first);
	}
	// cout << "push back : " << x << '\n';
	topo.push_back(x);
}
void f(int x){
	for(int i=0; i<G[x].size(); ++i){
		pii nxt=G[x][i];
		if(dist[nxt.first]<dist[x]+nxt.second){
			dist[nxt.first]=dist[x]+nxt.second;
			revG[nxt.first].clear();
			revG[nxt.first].push_back(x);
		}
		else if(dist[nxt.first]==dist[x]+nxt.second){
			revG[nxt.first].push_back(x);
		}
	}
}
void dfs2(int x){
	if(visit2[x]) return;
	// cout << "x : " << x << '\n';
	for(int i=0; i<revG[x].size(); ++i){
		res++;
		dfs2(revG[x][i]);
	}
	visit2[x]=1;
}
void init(){
	for(int i=0; i<10001; ++i){
		dist[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	init();
	for(int i=0; i<m; ++i){
		int u,v,w; cin>>u>>v>>w;
		G[u].push_back({v,w});
	}
	cin>>S>>E;
	dfs1(S); // topo가 역순으로 채워짐.
	for(int i=topo.size()-1; i>=0; --i){
		// cout << "topo[" << i << "]="<<topo[i] << '\n';
		f(topo[i]);
	}
	cout << dist[E] << '\n';
	dfs2(E);
	cout << res << '\n';
}