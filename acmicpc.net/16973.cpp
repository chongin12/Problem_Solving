#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
struct node {
    int x, y, k;
};
int arr[1001][1001];
int visited[1001][1001];
int N, M;
int H, W, Sr, Sc, Fr, Fc;
bool isSafe(int x, int y){
    return x>=0 && x<N && y>=0 && y<M && arr[x][y]!=1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    cin>>H>>W>>Sr>>Sc>>Fr>>Fc;
    Sr--, Sc--, Fr--, Fc--;
    queue<node> q;
    q.push({Sr, Sc, 0});
    visited[Sr][Sc]=1;
    int res=-1;
    while(!q.empty()){
        node cur = q.front(); q.pop();
        // cout << "cur : " << cur.x << ", " << cur.y << " | " << cur.k << '\n';
        if(cur.x == Fr && cur.y == Fc){
            res=cur.k;
            break;
        }
        for(int i=0; i<4; ++i){
            bool flag=true;
            int nOx=cur.x+dx[i];
            int nOy=cur.y+dy[i];
            if(!isSafe(nOx, nOy) || visited[nOx][nOy]) continue;
            for(int j=0; j<W; ++j){
                int nx=nOx;
                int ny=nOy+j;
                if(!isSafe(nx,ny)){
                    flag=false;
                    break;
                }
            }
            if(!flag) continue;
            for(int j=0; j<W; ++j){
                int nx=nOx+H-1;
                int ny=nOy+j;
                if(!isSafe(nx,ny)){
                    flag=false;
                    break;
                }
            }
            if(!flag) continue;
            for(int j=0; j<H; ++j){
                int nx=nOx+j;
                int ny=nOy;
                if(!isSafe(nx,ny)){
                    flag=false;
                    break;
                }
            }
            if(!flag) continue;
            for(int j=0; j<H; ++j){
                int nx=nOx+j;
                int ny=nOy+W-1;
                if(!isSafe(nx,ny)){
                    flag=false;
                    break;
                }
            }
            if(flag){
                q.push({nOx, nOy, cur.k+1});
                visited[nOx][nOy]=1;
            }
        }
    }
    cout << res << '\n';
}