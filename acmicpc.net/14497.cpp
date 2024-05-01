#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<string> v;
int visited[301][301]; // 갈 수 있는 모든 영역 체크
int N, M; 
int x1, Y1, x2, y2; 
int toFill[301][301];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void ff(){ // 한 꺼풀 벗기기
    memset(toFill, 0, sizeof toFill);
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(v[i][j]=='0') continue;
            for(int k=0; k<4; ++k){
                int nx=i+dx[k], ny=j+dy[k];
                if(nx>=0 && nx<N && ny>=0 && ny<M && visited[nx][ny]){
                    toFill[i][j]=1;
                    break;
                }
            }
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(toFill[i][j]) v[i][j]='0';
        }
    }
}
void floodFill(int cnt) { // x1, y1에서 bfs돌리기. visit에 cnt로 표시
    queue<pii> q;
    q.push({x1,Y1});
    visited[x1][Y1]=cnt;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; ++i){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && visited[nx][ny]!=cnt && v[nx][ny]=='0'){
                visited[nx][ny]=cnt;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    cin>>x1>>Y1>>x2>>y2; x1--,Y1--,x2--,y2--;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        v.push_back(str);
    }
    visited[x1][Y1] = 1;
    floodFill(1);
    for(int cnt=2;;++cnt){
        ff();
        floodFill(cnt);
        if(visited[x2][y2]) {
            cout << cnt-1 << '\n';
            break;
        }
    }
}