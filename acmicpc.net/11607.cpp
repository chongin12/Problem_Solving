#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y, w;
};
int arr[501][501];
int visited[501][501];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    for(int i=0; i<n; ++i){
        string str; cin>>str;
        for(int j=0; j<m; ++j){
            arr[i][j]=str[j]-'0';
        }
    }
    queue<Node> q;
    q.push({0,0,0});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.x==n-1 && cur.y==m-1){
            cout << cur.w << '\n';
            return 0;
        }
        for(int i=0; i<4; ++i){
            int nx = cur.x + dx[i] * arr[cur.x][cur.y];
            int ny = cur.y + dy[i] * arr[cur.x][cur.y];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny]){
                visited[nx][ny]=1;
                q.push({nx,ny,cur.w+1});
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}