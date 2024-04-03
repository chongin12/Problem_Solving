#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF = 987654321;
int visited[130][130] = {0,};
int arr[130][130] = {0,};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct Node {
    int x, y, val;
};
void init(){
    for(int i=0; i<130; ++i){
        for(int j=0; j<130; ++j){
            visited[i][j]=INF;
            arr[i][j]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int t=1; ; ++t){
        init();
        int N; cin>>N;
        if(N==0) return 0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                cin>>arr[i][j];
            }
        }
        queue<Node> q;
        q.push({0, 0, arr[0][0]});
        visited[0][0]=arr[0][0];
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(visited[cur.x][cur.y]!=cur.val) continue;
            for(int i=0; i<4; ++i){
                int nx=cur.x+dx[i];
                int ny=cur.y+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<N) {
                    if(visited[nx][ny]>cur.val+arr[nx][ny]){
                        visited[nx][ny]=cur.val+arr[nx][ny];
                        q.push({nx,ny,cur.val+arr[nx][ny]});
                    }
                }
            }
        }
        cout << "Problem " << t << ": " << visited[N-1][N-1] << '\n';
    }
}