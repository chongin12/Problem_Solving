#include <bits/stdc++.h>
using namespace std;
int arr[501][501];
int visited[501][501];
int N,M;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
bool flag;
void dfs(int x, int y, int k){
    visited[x][y]=1;
    for(int i=0; i<8; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<M){
            if(arr[nx][ny]>k){
                flag=false;
            }
            if(visited[nx][ny]) continue;
            if(arr[nx][ny]==k){
                dfs(nx, ny, k);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    int ans=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(visited[i][j]) continue;
            flag=true;
            dfs(i, j, arr[i][j]);
            if(flag) ans++;
        }
    }
    cout << ans << '\n';
}