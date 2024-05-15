#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int visited[1001][1001][2];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct Node {
    int x, y, k, d; // x, y, 벽 부수기 여부, depth
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    int Hx, Hy; cin>>Hx>>Hy;
    int Ex, Ey; cin>>Ex>>Ey;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            cin>>arr[i][j];
        }
    }
    queue<Node> q;
    q.push({Hx, Hy, 0, 0});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        // cout << "cur : (" << cur.x << ", " << cur.y << ") : " << cur.k << " , " << cur.d << '\n';
        if(cur.x == Ex && cur.y == Ey){
            cout << cur.d << '\n';
            return 0;
        }
        for(int i=0; i<4; ++i){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx>0 && nx<=N && ny>0 && ny<=M){
                if(arr[nx][ny]==0){
                    if(!visited[nx][ny][cur.k]){
                        visited[nx][ny][cur.k]=1;
                        q.push({nx, ny, cur.k, cur.d+1});
                    }
                }
                else {
                    if(cur.k == 0 && !visited[nx][ny][1]){
                        visited[nx][ny][1]=1;
                        q.push({nx, ny, 1, cur.d+1});
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
}