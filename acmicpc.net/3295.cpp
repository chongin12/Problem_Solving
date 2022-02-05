#include <bits/stdc++.h>
using namespace std;
const int MN=1000;
vector<int> G[MN*2];
int p[MN*2], visited[MN*2];
void init(){
	for(int i=0; i<MN*2; ++i){
		G[i].clear();
	}
	fill(p, p+MN*2, -1);
}
int dfs(int x){
	for(auto nxt:G[x]){
		if(visited[nxt]) continue;
		visited[nxt]=1;
		if(p[nxt]==-1 || dfs(p[nxt])){
			p[nxt]=x;
			return 1;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin>>T;
	while(T--){
		init();
		int n,m; cin>>n>>m;
		for(int i=0; i<m; ++i){
			int a,b; cin>>a>>b;
			G[a].push_back(b+MN);
		}
		int cnt=0;
		for(int i=0; i<n; ++i){
			fill(visited, visited+MN*2, 0);
			if(dfs(i)) cnt++;
		}
		// for(int i=0; i<n; ++i){
		// 	if(p[i+MN]!=-1){
		// 		cout << p[i+MN] << " -> " << i << '\n';
		// 	}
		// }
		cout << cnt << '\n';
	}
}