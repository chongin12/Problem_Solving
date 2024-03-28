#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int MN=201;
vector<int> G[MN*2+1];
int avail[201][201];
pii range[201];
pii maxrange[201];
int matching[MN*2+1];
int visited[MN*2+1];
int bip(int u){
	if(visited[u]) return false;
	visited[u]=1;
	for(auto nxt:G[u]){
		if(matching[nxt]==0 || bip(matching[nxt])){
			matching[nxt]=u;
			return true;
		}
	}	
	return false;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M; cin>>N>>M;
	for(int i=1; i<=N; ++i){
		range[i]={1,N};
		maxrange[i]={1,N};
		for(int j=1; j<=N; ++j){
			avail[i][j]=1;
		}
	}
	for(int i=0; i<M; ++i){
		int a,b,c,d; cin>>a>>b>>c>>d;
		if(c < range[d].first || range[d].second < b){
			cout << "-1\n";
			return 0;
		}
		range[d].first = max(range[d].first, b);
		range[d].second = min(range[d].second, c);
		maxrange[d].first = min(range[d].first, b);
		maxrange[d].second = max(range[d].second, c);
		for(int j=1; j<range[d].first; ++j){
			avail[d][j]=0;
		}
		for(int j=range[d].second+1; j<=N; ++j){
			avail[d][j]=0;
		}
		if(a==1){
			for(int i=d+1; i<=N; ++i){
				for(int j=maxrange[d].first; j<=maxrange[d].second; ++j){
					avail[i][j]=0;
				}
			}
		}
		else{
			for(int i=d-1; i>=1; --i){
				for(int j=maxrange[d].first; j<=maxrange[d].second; ++j){
					avail[i][j]=0;
				}
			}
		}
	}
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
//			cout << "avail["<<i<<"]["<<j<<"]="<<avail[i][j]<<'\n';
			if(avail[i][j]){
				G[i].push_back(j+MN);
			}
		}
	}
	int res=0;
	for(int i=1; i<=N; ++i){
		memset(visited, 0, sizeof visited);
		if( bip(i)) res++;
	}
	if(res!=N){
		cout << "-1\n";
	} else {
		for(int i=1; i<=N; ++i){
			cout << matching[i+MN] << ' ';
		}
		cout << '\n';
	}
}
