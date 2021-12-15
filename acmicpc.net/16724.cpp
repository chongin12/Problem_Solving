#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int dir[1001][1001];
int visit[1001][1001];
int res=0;
void dfs(int x, int y, int phase){
	if(visit[x][y]==phase){
		res++;
		return;
	}
	if(visit[x][y]){
		return;
	}
	visit[x][y]=phase;
	int di=dir[x][y];
	dfs(x+dx[di], y+dy[di], phase);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M; cin>>N>>M;
	for(int i=0; i<N; ++i){
		string str; cin>>str;
		for(int j=0; j<M; ++j){
			if(str[j]=='U') dir[i][j]=0;
			if(str[j]=='D') dir[i][j]=1;
			if(str[j]=='L') dir[i][j]=2;
			if(str[j]=='R') dir[i][j]=3;
		}
	}
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			if(!visit[i][j]) dfs(i,j,i*M+j+1);
		}
	}
	cout << res << '\n';
}