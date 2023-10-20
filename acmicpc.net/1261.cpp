#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<string> arr;
const int INF = 987654321;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int visited[101][101];
int M, N;
vector<pii> v;
void floodFill(int x, int y, int k){
    queue<pii> q;
    q.push({x,y});
    visited[x][y]=k;
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        for(int i=0; i<4; ++i){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && visited[nx][ny]!=k){
                if(arr[nx][ny]=='0'){
                    visited[nx][ny]=k;
                    q.push({nx,ny});
                }
                else {
                    visited[nx][ny]=k;
                    arr[nx][ny]='0';
                }
            }
        }
    }
}
int main(){
    cin>>M>>N;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        arr.push_back(str);
    }
    // 처음에 갈 수 있는 곳과 인접한 것을 모두 큐에 넣음.
    // 큐에 넣은 것들을 0으로 바꾸고 floodFill
    for(int k=1; ; ++k){
        floodFill(0,0,k);
        if(visited[N-1][M-1]==k){
            cout << k-1 << '\n';
            return 0;
        }
    }
}