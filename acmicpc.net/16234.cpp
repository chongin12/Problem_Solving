#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int N, L, R;
int arr[51][51];
int visited[51][51];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vector<pii> vlog;
void init(){
    memset(visited, 0, sizeof visited);
}
void dfs(int x, int y){
    visited[x][y]=1;
    vlog.push_back({x,y});
    for(int i=0; i<4; ++i){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny] && abs(arr[x][y]-arr[nx][ny])>=L && abs(arr[x][y]-arr[nx][ny])<=R) {
            dfs(nx, ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>L>>R;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
        }
    }
    int res=0;
    while(1){
        init();
        res++;
        bool flag=0; // 인구 이동이 발생했는지 여부
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                if(visited[i][j]) continue;
                vlog.clear();
                dfs(i, j);
                int cnt=vlog.size();
                int acc=0;
                int isSame=true;
                for(auto it:vlog){
                    if(arr[it.first][it.second]!=arr[vlog[0].first][vlog[0].second]){
                        isSame=false;
                    }
                    acc+=arr[it.first][it.second];
                }
                if(isSame){
                    continue;
                } else {
                    flag=true;
                }
                acc/=cnt;
                for(auto it:vlog){
                    arr[it.first][it.second]=acc;
                }
            }
        }
        if(!flag){
            break;
        }
    }
    cout << res-1 << '\n';
}