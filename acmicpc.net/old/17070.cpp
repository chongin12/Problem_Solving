#include <bits/stdc++.h>
using namespace std;
int arr[20][20];
int n;
int res;
//dir : 0=가로, 1=대각선, 2=세로
void bfs(int x, int y, int dir){
	if(x<0 || x>=n || y<0 || y>=n){
		return;
	}
	if(arr[x][y]==1){
		return;
	}
	if(dir==1 && (arr[x-1][y]==1 || arr[x][y-1]==1)){
		return;
	}
	if(x==n-1 && y==n-1){
		res+=1;
		return;
	}
	if(dir==0){
		bfs(x,y+1,0);
		bfs(x+1,y+1,1);
	}
	else if(dir==1){
		bfs(x,y+1,0);
		bfs(x+1,y+1,1);
		bfs(x+1,y,2);
	}
	else{
		bfs(x+1,y,2);
		bfs(x+1,y+1,1);
	}
}
int main(){
	cin>>n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> arr[i][j];
		}
	}
	bfs(0,1,0);
	cout << res << '\n';
}