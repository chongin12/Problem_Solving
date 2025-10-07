#include <bits/stdc++.h>
using namespace std;
int arr[102][102];
int visited[102][102];
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int r=0;
int dfs(int x, int y){
    visited[x][y]=1;
    int ret=1;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(arr[nx][ny]==0 || visited[nx][ny]==1) continue;
        ret+=dfs(nx, ny);
    }
    return ret;
}
int main(){
    int N, M, K; cin>>N>>M>>K;
    for(int i=0; i<K; ++i){
        int r, c; cin>>r>>c;
        arr[r][c]=1;
    }
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(arr[i][j]==0 || visited[i][j]) continue;
            r=max(r,dfs(i, j));
        }
    }
    cout <<r << '\n';
}