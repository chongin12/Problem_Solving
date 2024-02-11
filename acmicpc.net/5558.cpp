#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;
vector<string> arr;
pii pos[10];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int visited[1001][1001];
int res;
int H, W, N;
void init(){
    memset(visited, 0, sizeof visited);
}
void bfs(int start){
    init();
    int si=pos[start].x;
    int sj=pos[start].y;
    queue<pair<pii, int> > q;
    q.push({{si, sj}, 0});
    visited[si][sj]=1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(arr[cur.x.x][cur.x.y]==start+1+'0'){
            res+=cur.y;
            return;
        }
        for(int i=0; i<4; ++i){
            int ni=cur.x.x+dx[i];
            int nj=cur.x.y+dy[i];
            if(ni>=0 && ni<H && nj>=0 && nj<W && !visited[ni][nj] && arr[ni][nj]!='X'){
                visited[ni][nj]=1;
                q.push({{ni,nj},cur.y+1});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>H>>W>>N;
    for(int i=0; i<H; ++i){
        string str; cin>>str;
        for(int j=0; j<W; ++j){
            if(str[j]=='S') str[j]='0';
            if(str[j]>='0' && str[j]<='9'){
                pos[str[j]-'0']={i,j};
            }
        }
        arr.push_back(str);
    }
    for(int i=0; i<N; ++i){
        bfs(i);
    }
    cout << res << '\n';
}