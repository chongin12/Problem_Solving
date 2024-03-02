#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int dx[][3]={
    {-1, -2, -3},
    {-1, -2, -3},
    {0, -1, -2},
    {0, 1, 2},
    {1, 2, 3},
    {1, 2, 3},
    {0, 1, 2},
    {0, -1, -2},
};
int dy[][3]={
    {0, -1, -2},
    {0, 1, 2},
    {1, 2, 3},
    {1, 2, 3},
    {0, 1, 2},
    {0, -1, -2},
    {-1, -2, -3},
    {-1, -2, -3},
};
struct node {
    int x, y, k;
};
int visited[11][11];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int R1, C1; cin>>R1>>C1;
    int R2, C2; cin>>R2>>C2;
    int N=10, M=9;
    queue<node> q;
    q.push({R1, C1, 0});
    visited[R1][C1]=1;
    while(!q.empty()){
        node cur = q.front(); q.pop();
        if(cur.x==R2 && cur.y == C2){
            cout << cur.k << '\n';
            return 0;
        }
        for(int i=0; i<8; ++i){
            bool pass=true;
            for(int j=0; j<3; ++j){
                int nx=cur.x+dx[i][j], ny=cur.y+dy[i][j];
                if(nx>=0 && nx<N && ny>=0 && ny<M){
                    if(j<2 && nx==R2 && ny==C2){
                        pass=false;
                        break;
                    }
                    if(j==2 && visited[nx][ny]==1){
                        pass=false;
                        break;
                    }
                } else {
                    pass=false;
                    break;
                }
            }
            if(pass){
                int nx=cur.x+dx[i][2], ny=cur.y+dy[i][2];
                q.push({nx, ny, cur.k+1});
                visited[nx][ny]=1;
            }
        }
    }
    cout << "-1\n";
}