#include <bits/stdc++.h>
using namespace std;
vector<int> G[10001];
int visit[10001];
int cut[10001];
vector<int> res;
int cnt;
int dfs(int x, bool isRoot){ // 방문한 노드들 중 가장 작은 cnt값을 리턴한다.
	visit[x]=++cnt;
	int ret=visit[x];
	int child=0;
	for(auto nxt:G[x]){
		if(visit[nxt]){
			ret = min(ret, visit[nxt]);
			continue;
		}
		child++;
		int minimum = dfs(nxt, false); // 다음 경로들 중 가장 작은 cnt를 찾기
		if(!isRoot && minimum>=visit[x]){
			if(cut[x]==0) res.push_back(x);
			cut[x]=1;
		}
		ret=min(ret, minimum);
	}
	if(isRoot && child>=2){
		if(cut[x]==0) res.push_back(x);
		cut[x]=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int V,E; cin>>V>>E;
	for(int i=0; i<E; ++i){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1; i<=V; ++i){
		if(!visit[i]){
			dfs(i, true);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for(auto it:res) cout << it << ' ';
	cout << '\n';
}