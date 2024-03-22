#include <bits/stdc++.h>
using namespace std;
int visited[1011][1011];
struct node {
    int x, y, k, type; // type : 0이 상근, 1이 불
};
void init(){
    memset(visited, 0, sizeof visited);
}
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int w, h; cin>>h>>w;
    vector<string> v;
    queue<node> q;
    int si, sj;
    for(int i=0; i<h; ++i){
        string str; cin>>str;
        v.push_back(str);
        for(int j=0; j<w; ++j){
            if(str[j]=='F'){
                q.push({i,j,0,1});
                visited[i][j]=1;
            }
            else if(str[j]=='J'){
                si=i;
                sj=j;
            }
        }
    }
    q.push({si,sj,0,0});
    visited[si][sj]=1;
    int res=-1;
    while(!q.empty()){
        node cur = q.front(); q.pop();
        // cout << "cur : " << cur.x << ", " << cur.y << " | " << cur.k << ", type : " << cur.type << '\n';
        if(cur.type==0 && (cur.x==0 || cur.x==h-1 || cur.y==0 || cur.y==w-1)){
            res=cur.k+1;
            break;
        }
        for(int i=0; i<4; ++i){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx<0 || nx>h-1 || ny<0 || ny>w-1) continue;
            if(visited[nx][ny] || v[nx][ny]=='#') {
                continue;
            }
            q.push({nx,ny,cur.k+1,cur.type});
            visited[nx][ny]=1;
        }
    }
    if(res==-1) cout << "IMPOSSIBLE\n";
    else cout << res << '\n';
}