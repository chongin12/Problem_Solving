#include <bits/stdc++.h>
using namespace std;
const int MN=100;
vector<int> G[MN*2];
int p[MN*2];
int visited[MN*2];
int dfs(int x){
	for(auto nxt:G[x]){
		if(visited[nxt]) continue;
		visited[nxt]=1;
		if(p[nxt]==-1 || dfs(p[nxt])){
			p[nxt]=x;
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M; cin>>N>>M;
	for(int i=0; i<M; ++i){
		int a,b; cin>>a>>b; a--; b--;
		G[a].push_back(b+MN);
	}
	int res=0;
	fill(p, p+MN*2, -1);
	for(int i=0; i<N; ++i){
		fill(visited, visited+MN*2, 0);
		if(dfs(i)) res++;
	}
	cout << res << '\n';
}