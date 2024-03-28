#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using piii=tuple<int,int,int>;
int arr[51][51];
int visited[51][51];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int L, W;
int bfs(int i, int j, int phase){
    int ret=0;
    queue<piii> q;
    q.push({i,j,0});
    visited[i][j]=phase;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        auto [ci, cj, depth] = cur;
        ret=max(ret,depth);
        for(int k=0; k<4; ++k){
            int ni=ci+dx[k];
            int nj=cj+dy[k];
            if(ni>=0 && ni<L && nj>=0 && nj<W && arr[ni][nj]==0 && visited[ni][nj]!=phase) {
                visited[ni][nj]=phase;
                q.push({ni,nj,depth+1});
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>L>>W;
    for(int i=0; i<L; ++i){
        string str; cin>>str;
        for(int j=0; j<W; ++j){
            if(str[j]=='W') arr[i][j]=1;
            else arr[i][j]=0;
        }
    }
    int res=0;
    for(int i=0; i<L; ++i){
        for(int j=0; j<W; ++j){
            if(arr[i][j]==0){
                res=max(res,bfs(i, j, i*W+j+1));
            }
        }
    }
    cout << res << '\n';
}