#include <bits/stdc++.h>
using namespace std;
int arr[102][102];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct edge{
	int x,y;
	edge(int x, int y): x(x),y(y) {}
};
int main(){
	int n,m; cin>>n>>m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			cin >> arr[i][j];
		}
	}
	int t=0;
	while(1){
		bool pass=true;
		for(int i=1; i<=n; ++i){
			if(!pass) break;
			for(int j=1; j<=m; ++j){
				if(arr[i][j]==1){
					pass=false;
					break;
				}
			}
		}
		if(pass){
			break;
		}
		t+=1;
		queue<edge> q;
		q.push(edge(0,0));
		int temp[102][102]={0,};
		int visit[102][102]={0,};
		visit[0][0]=1;
		while(!q.empty()){
			edge c=q.front();
			q.pop();
			for(int i=0; i<4; ++i){
				int nx=c.x+dx[i];
				int ny=c.y+dy[i];
				if(nx>=0 && nx<=n && ny>=0 && ny<=m && !visit[nx][ny]){
					if(arr[nx][ny]==1){
						temp[nx][ny]+=1;
					}
					else{
						visit[nx][ny]=1;
						q.push(edge(nx,ny));
					}
				}
			}
		}
		for(int i=0; i<=n; ++i){
			for(int j=0; j<=m; ++j){
				if(temp[i][j]>=2){
					arr[i][j]=0;
				}
			}
		}
	}
	cout << t << '\n';
}