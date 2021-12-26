#include <bits/stdc++.h>
using namespace std;
const int MN=10000;
int N,M;
vector<int> G[2*MN+1];
vector<int> st;
vector<int> RG[2*MN+1];
vector<vector<int> > scc;
int visit[2*MN+1];
void dfs1(int x){
	visit[x]=1;
	for(int i=0; i<G[x].size(); ++i){
		if(!visit[G[x][i]]) dfs1(G[x][i]);
	}
	st.push_back(x);
}
void dfs2(int x){
	visit[x]=1;
	for(int i=0; i<RG[x].size(); ++i){
		if(!visit[RG[x][i]]) dfs2(RG[x][i]);
	}
	scc.back().push_back(x);
}
int toNot(int a){
	if(a<=N) a+=N;
	else a-=N;
	return a;
}
void visitClear(){
	for(int i=0; i<2*MN+1; ++i){
		visit[i]=0;
	}
}
void init(){
	for(int i=0; i<MN*2+1; ++i){
		G[i].clear();
		RG[i].clear();
	}
	st.clear();
	for(int i=0; i<scc.size(); ++i){
		scc[i].clear();
	}
	scc.clear();
	visitClear();
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(1){
		init();
		cin >> N >> M;
		if(cin.eof()) return 0;
		for(int i=0; i<M; ++i){
			int a,b; cin>>a>>b;
			if(a<0) a=-a+N;
			if(b<0) b=-b+N;
			G[toNot(a)].push_back(b);
			G[toNot(b)].push_back(a);
			RG[a].push_back(toNot(b));
			RG[b].push_back(toNot(a));
		}
		G[1+N].push_back(1);
		RG[1].push_back(1+N);
		for(int i=1; i<=2*N; ++i){
			if(!visit[i]) dfs1(i);
		}
		visitClear();
		reverse(st.begin(), st.end());
		for(int i=0; i<st.size(); ++i){
			int x=st[i];
			if(visit[x]) continue;
			scc.push_back(vector<int>());
			dfs2(x);
		}
		visitClear();
		// for(int i=0; i<scc.size(); ++i){
		// 	for(int j=0; j<scc[i].size(); ++j){
		// 		cout << scc[i][j] << ", ";
		// 	}
		// 	cout << '\n';
		// }
		bool flag=false;
		for(int i=0; i<scc.size(); ++i){
			for(int j=0; j<scc[i].size(); ++j){
				int x=scc[i][j];
				if(visit[toNot(x)]){
					cout << "no\n";
					flag=true;
					break;
				}
				visit[x]=1;
			}
			for(int j=0; j<scc[i].size(); ++j){
				visit[scc[i][j]]=0;
			}
			if(flag) break;
		}
		if(!flag) cout << "yes\n";
	}
}