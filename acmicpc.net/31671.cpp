#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int A[2001][2001];
int visited[2001][2001];
struct Node {
    int x, y, v;
};
int main(){
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int x, y; cin>>x>>y;
        A[x][y]=1;
    }
    queue<Node> q;
    q.push({0,0,0});
    visited[0][0]=1;
    int res=-1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        // cout << "cur : " << cur.x << ", " << cur.y << ", " << cur.v << '\n';
        if(cur.x==2*N && cur.y==0){
            res=max(res,cur.v);
            continue;
        }
        for(int i=0; i<2; ++i){
            int nx=cur.x+1;
            int ny=cur.y+1+2*(-1*i);
            if(nx<=2*N && ny>=0 && ny<=N){
                if((nx<N && ny<=nx) || (nx>=N && ny<=(N+N-nx))){
                    if(!visited[nx][ny] && !A[nx][ny]){
                        q.push({nx,ny,max(cur.v,ny)});
                        visited[nx][ny]=1;
                    }
                }
            }
        }
    }
    cout << res << '\n';
}