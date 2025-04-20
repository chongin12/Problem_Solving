#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct Node {
    int x, y, depth, k;
};
int visited[1001][1001];
int main(){
    int N, M, K; cin>>N>>M>>K;
    for(int i=0; i<1001; ++i){
        for(int j=0; j<1001; ++j){
            visited[i][j]=-1;
        }
    }
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    queue<Node> q;
    q.push({0,0,1,0});
    visited[0][0]=0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.x==N-1 && cur.y==M-1){
            cout << cur.depth << '\n';
            return 0;
        }
        if(visited[cur.x][cur.y]!=cur.k) continue;
        for(int i=0; i<4; ++i){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(v[nx][ny]=='0' && visited[nx][ny]==-1){
                    visited[nx][ny]=cur.k;
                    q.push({nx,ny,cur.depth+1,cur.k});
                }
                else if(v[nx][ny]=='0' && visited[nx][ny]!=-1 && visited[nx][ny]>cur.k){
                    visited[nx][ny]=cur.k;
                    q.push({nx,ny,cur.depth+1,cur.k});
                }
                else if(v[nx][ny]=='1' && cur.k+1<=K && visited[nx][ny]==-1){
                    visited[nx][ny]=cur.k+1;
                    q.push({nx,ny,cur.depth+1,cur.k+1});
                }
                else if(v[nx][ny]=='1' && cur.k+1<=K && visited[nx][ny]!=-1 && visited[nx][ny]>cur.k+1){
                    visited[nx][ny]=cur.k+1;
                    q.push({nx,ny,cur.depth+1,cur.k+1});
                }
            }
        }
    }
    cout << "-1\n";
}