#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using piii=pair<int,pair<int,int> >;
int arr[101][101];
int grp[101][101];
int visited[101][101];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int N;
void bfs1(int x, int y, int k){
	queue<pii> q;
	q.push({x,y});
	visited[x][y]=1;
	grp[x][y]=k;
	while(!q.empty()){
		pii cur = q.front(); q.pop();
		for(int i=0; i<4; ++i){
			int nx = cur.first+dx[i];
			int ny = cur.second+dy[i];
			if(nx>=0 && nx<N && ny>=0 && ny<N && arr[nx][ny]==1 && !visited[nx][ny]){
				q.push({nx,ny});
				visited[nx][ny]=1;
				grp[nx][ny]=k;
			}
		}
	}
}	
int bfs2(int x, int y, int k){
	queue<piii> q;
	q.push({0, {x,y}});
	while(!q.empty()){
		piii cur = q.front(); q.pop();
		for(int i=0; i<4; ++i){
			int nx = cur.second.first+dx[i];
			int ny = cur.second.second+dy[i];
			if(nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny]){
				if(arr[nx][ny]==0){
					q.push({cur.first+1,{nx,ny}});
					visited[nx][ny]=1;
				}
				else if(arr[nx][ny]==1 && grp[nx][ny]!=k){
					return cur.first;
				}
			}
		}
	}
	return 987654321;
}
	
void init(){
	for(int i=0; i<101; ++i){
		for(int j=0; j<101; ++j){
			visited[i][j]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>N;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			cin>>arr[i][j];
		}	
	}
	int cnt=0;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(visited[i][j]) continue;
			if(arr[i][j]==0) continue;
			bfs1(i,j, ++cnt);
		}	
	}
//	for(int i=0; i<N; ++i){
//		for(int j=0; j<N; ++j){
//			cout << grp[i][j] << ' ';
//		}	
//		cout << '\n';
//	}
	int res = 987654321;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(arr[i][j]==0) continue;
			init();
			int r = bfs2(i, j, grp[i][j]);
			res=min(res,r);
		}	
	}
	cout << res << '\n';
}
