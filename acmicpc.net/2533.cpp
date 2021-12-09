//dp[i][0] : 리프~i까지 i를 얼리어답터로 포함시키지 않았을 때 최소 얼리어답터 수
//dp[i][1] : 리프~i까지 i를 얼리어답터로 포함시켰을 때 최소 얼리어답터 수
//거꾸로 bfs?
#include <bits/stdc++.h>
using namespace std;
int dp[1000001][2];
vector<int> G[1000001];
int N;
int root;
void dfs(int x, int prev){
	if(G[x].size()==1 && G[x][0]==prev){ //리프노드
		dp[x][0]=0;
		dp[x][1]=1;
		return;
	}
	for(auto it:G[x]){
		if(it==prev) continue;
		dfs(it, x);
		dp[x][0]+=dp[it][1];
		dp[x][1]+=min(dp[it][0], dp[it][1]);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=1; i<=N-1; ++i){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1; i<=N; ++i){
		dp[i][1]=1;
	}
	root=1;// 루트는 아무거나 잡아도 됨.
	dfs(root, 0);
	cout << min(dp[root][0], dp[root][1])<<'\n';
}