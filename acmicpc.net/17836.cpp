#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int arr[102][102];
int visited[102][102];
struct Node {
    int x, y;
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, T; cin>>N>>M>>T;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    queue<Node> q;
    q.push({0,0});
    visited[0][0]=1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; ++i){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && arr[nx][ny]!=1 && visited[nx][ny]==0){
                visited[nx][ny]=visited[cur.x][cur.y]+1;
                q.push({nx, ny});
            }
        }
    }
    int res=visited[N-1][M-1];
    if(res==0) res=987654321; 
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(arr[i][j]==2 && visited[i][j]!=0) res=min(res,visited[i][j]+N-1-i+M-1-j);
        }
    }
    --res;
    if(res>T || res==987654321) cout << "Fail\n";
    else cout << res << '\n';
}