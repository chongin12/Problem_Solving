#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int visited[10][10];
int res=0;int R, C, K; 
void dfs(int i, int j, int cnt){
    // cout << "i : " << i<< ", j : " << j << ", cnt : " << cnt << '\n';
    if(i==0 && j==C-1 && cnt==0){
        res++;
        return;
    }
    if(cnt<=0) return;
    if(i==0 && j==C-1) return;
    visited[i][j]=1;
    for(int a=0; a<4; ++a){
        int nx=i+dx[a], ny=j+dy[a];
        if(nx>=0 && nx<R && ny>=0 && ny<C && !visited[nx][ny] && v[nx][ny]!='T'){
            dfs(nx, ny, cnt-1);
        }
    }
    visited[i][j]=0;
}
int main(){
    cin>>R>>C>>K;
    for(int i=0; i<R; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    dfs(R-1, 0, K-1);
    cout << res << '\n';
}