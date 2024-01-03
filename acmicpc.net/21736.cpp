#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int cnt=0;
int N, M; 
int visited[601][601];
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
void dfs(int x, int y){
    if(visited[x][y]) return;
    visited[x][y]=1;
    if(v[x][y]=='P') cnt++;
    for(int i=0; i<4; ++i){
        int cx=x+dx[i], cy=y+dy[i];
        if(cx>=0 && cx<N && cy>=0 && cy<M && !visited[cx][cy] && v[cx][cy]!='X'){
            dfs(cx, cy);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    int x,y;
    for(int i=0; i<N; ++i){
        string s; cin>>s;
        for(int j=0; j<M; ++j){
            if(s[j]=='I'){
                x=i,y=j;
            }
        }
        v.push_back(s);
    }
    dfs(x,y);
    if(cnt==0) cout << "TT\n";
    else cout << cnt << '\n';
}