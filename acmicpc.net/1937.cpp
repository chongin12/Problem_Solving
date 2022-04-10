#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int arr[501][501];
int dp[501][501];
int visited[501][501];
int N;
int dfs(int x, int y){
    if(dp[x][y]) return dp[x][y];
    visited[x][y]=2;
    int ret=0;
    for(int i=0; i<4; ++i){
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
        if(visited[nx][ny]==2) continue;
        if(arr[nx][ny]>arr[x][y]) ret=max(ret,dfs(nx, ny));
    }
    visited[x][y]=1;
    return dp[x][y]=1+ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
        }
    }
    int res=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            res=max(res,dfs(i,j));
        }
    }
    cout << res << '\n';
}