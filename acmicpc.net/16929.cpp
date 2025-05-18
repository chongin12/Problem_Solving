#include <bits/stdc++.h>
using namespace std;
vector<string> v;
bool flag=false;
int visited[51][51];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int N, M;
void f(int x, int y, int prevx, int prevy, int w){
    visited[x][y]=w;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx==prevx && ny==prevy) continue;
        if(nx>=0 && nx<N && ny>=0 && ny<M){
            if(v[nx][ny]!=v[x][y]) continue;
            if(visited[nx][ny]==w){
                flag=true;
                return;
            }
            f(nx, ny, x, y, w);
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(!visited[i][j]) f(i, j, -1, -1, i*N+j+1);
        }
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
}