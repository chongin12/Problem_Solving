#include <bits/stdc++.h>
using namespace std;
int arr[501][501];
int visited[501][501];
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
int N, M, K;
void dfs(int i, int j){
    if(visited[i][j]) return;
    visited[i][j]=1;
    for(int w=0; w<4; ++w){
        int nx=i+dx[w], ny=j+dy[w];
        if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny] && abs(arr[nx][ny]-arr[i][j])<=K){
            dfs(nx,ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M>>K;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    int r=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(visited[i][j]) continue;
            dfs(i, j);
            r++;
        }
    }
    cout << r << '\n';
}