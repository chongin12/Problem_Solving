#include <bits/stdc++.h>
using namespace std;
int arr[301][301];
int del[301][301];
int visited[301][301];
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
void init(){
    memset(del, 0, sizeof del);
    memset(visited, 0, sizeof visited);
}
int N, M;
void dfs(int i, int j){
    visited[i][j]=1;
    for(int k=0; k<4; ++k){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0 && nx<N && ny>=0 && ny<M && arr[nx][ny]>0 && !visited[nx][ny]){
            dfs(nx, ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    int cnt=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    while(1){
        cnt++;
        init();
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(arr[i][j]>0){
                    for(int k=0; k<4; ++k){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0 && nx<N && ny>=0 && ny<M && arr[nx][ny]==0){
                            del[i][j]+=1;
                        }
                    }
                }
            }
        }
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                arr[i][j]=max(0, arr[i][j]-del[i][j]);
            }
        }
        int flag=0; // 덩어리 수
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                if(arr[i][j]>0 && !visited[i][j]){
                    flag++;
                    dfs(i, j);
                }
            }
        }
        if(flag==0) {
            cout << "0\n";
            break;
        }
        else if(flag>=2){
            cout << cnt << '\n';
            break;
        }
    }
}