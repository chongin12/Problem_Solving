#include <bits/stdc++.h>
using namespace std;
int arr[51][51];
int visited[51][51];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int N, M;
int res=0;
// dir : 0동 1남 2서 3북
// dfs() : 현재 x,y에서 dir로 왔고 남은게 p일 때 물의 최대량
void dfs(int x, int y, int dir, int p, int acc){
    if(p==0) return;
    visited[x][y]=1;
    acc=acc+arr[x][y];
    // cout << "x : " << x << ", y : " << y << ", acc = " << acc << ", p="<<p << '\n';
    res=max(res,acc);
    for(int i=3; i<6; ++i){
        int nxtDir = (dir+i)%4;
        int nx = x+dx[nxtDir];
        int ny = y+dy[nxtDir];
        int needP = i==4 ? 1 : 2;
        if(needP>p) continue;
        if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny]){
            dfs(nx,ny,nxtDir,p-needP,acc);
        }
    }
    visited[x][y]=0;
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    int si,sj,p; cin>>si>>sj>>p;
    visited[si][sj]=1;
    res=arr[si][sj];
    for(int i=0; i<4; ++i){
        int nx = si+dx[i];
        int ny = sj+dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<M){
            dfs(nx,ny,i,p,arr[si][sj]);
        }
    }
    cout << res << '\n';
}