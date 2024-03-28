#include <bits/stdc++.h>
using namespace std;
const int MN = 1001;
vector<int> G[MN*2+20];
int matched[MN*2+20];
int visited[MN*2+20];
int bip_dfs(int u){
	if(visited[u]) return false;
	visited[u]=1;
	for(auto nxt:G[u]){
		if(matched[nxt]==0 || bip_dfs(matched[nxt])){
			matched[nxt]=u;
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M, K; cin>>N>>M>>K;
	for(int i=1; i<=N; ++i){
		int a; cin>>a;
		for(int j=0; j<a; ++j){
			int w; cin>>w;
			G[i].push_back(w);
			G[i+MN].push_back(w);
		}
	}
	int res=0;
	for(int i=1; i<=N; ++i){
		memset(visited, 0, sizeof visited);
		if(bip_dfs(i)) res++;
	}
	for(int i=1; i<=N && K!=0; ++i){
		memset(visited, 0, sizeof visited);
		if(bip_dfs(i+MN)) res++,K--;
	}
	cout << res << '\n';
}