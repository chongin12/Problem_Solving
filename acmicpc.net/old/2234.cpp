#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int arr[51][51];
int visited[51][51];
int room[51][51];
int cnt[2501];
int dfs(int x, int y, int r){
    if(visited[x][y]) return 0;
    visited[x][y]=1;
    room[x][y]=r;
    int ret=1;
    for(int i=0; i<4; ++i){
        if(!(arr[x][y] & (1<<i))){
            ret += dfs(x+dx[i], y+dy[i], r);
        }
    }
    return ret;
}
int main(){
    int M, N; cin>>M>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    int r=0;
    int maxCnt=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(!visited[i][j]){
                ++r;
                cnt[r] = dfs(i, j, r);
                maxCnt = max(maxCnt, cnt[r]);
            }
        }
    }
    cout << r << '\n';
    cout << maxCnt << '\n';
    int maxSize=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            for(int k=0; k<4; ++k){
                if(arr[i][j] & (1<<k)){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0 && ni<N && nj>=0 && nj<M && room[i][j]!=room[ni][nj]){
                        maxSize = max(maxSize, cnt[room[i][j]]+cnt[room[ni][nj]]);
                    }
                }
            }
        }
    }
    cout << maxSize << '\n';
}