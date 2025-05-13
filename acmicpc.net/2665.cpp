#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int visited[51][51];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct Node {
    int x, y, w;
};
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    visited[0][0]=1;
    queue<Node> q;
    q.push({0,0,1});
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        if(cur.x==N-1 && cur.y==N-1) continue;
        if(cur.w != visited[cur.x][cur.y]) continue;
        for(int i=0; i<4; ++i){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N){
                int isBlack = v[nx][ny]=='0';
                if((visited[nx][ny]==0 || visited[nx][ny]>cur.w+isBlack)){
                    visited[nx][ny]=cur.w+isBlack;
                    q.push({nx,ny,cur.w+isBlack});
                }
            }
        }
    }
    cout << visited[N-1][N-1]-1 << '\n';
}