#include <bits/stdc++.h>
using namespace std;
int N,M;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<string> v;
bool visited[3001][3001];
struct node {
    int x,y,l;
    node(int x, int y, int l):x(x),y(y),l(l){}
};
int bfs(int a, int b){
    visited[a][b]=true;
    queue<node> q;
    q.push(node(a,b,0));
    while(!q.empty()){
        node cur = q.front(); q.pop();
        if(v[cur.x][cur.y]>'2') return cur.l;
        for(int i=0; i<4; ++i){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && !visited[nx][ny] && v[nx][ny]!='1'){
                q.push(node(nx,ny,cur.l+1));
                visited[nx][ny]=true;
            }
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    int a,b;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(str);
        for(int j=0; j<M; ++j){
            if(str[j]=='2'){
                a=i,b=j;
            }
        }
    }
    int res=bfs(a,b);
    if(res==-1){
        cout << "NIE\n";
    }
    else{
        cout << "TAK\n";
        cout << res << '\n';
    }
}