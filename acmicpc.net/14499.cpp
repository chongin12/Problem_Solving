#include <bits/stdc++.h>
using namespace std;
int arr[30][30];
/*
*/
int dice[7];
int idx[5] = {1, 3, 4, 2, 5}; // 위쪽 기준 현재 위치, 동쪽, 서쪽, 북쪽, 남쪽
int dx[]={0, 0, 0, -1, 1};
int dy[]={0, 1, -1, 0, 0};
int main(){
    int N, M, x, y, K; cin>>N>>M>>x>>y>>K;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<K; ++i){
        int dir; cin>>dir;
        if(x+dx[dir]>=0 && x+dx[dir]<N && y+dy[dir]>=0 && y+dy[dir]<M){
            x=x+dx[dir];
            y=y+dy[dir];
        } else {
            continue;
        }
        // cout << "now x : " << x << ",  y : " << y << '\n';
        int spare = 21 - idx[0] - idx[1] - idx[2] - idx[3] - idx[4]; 
        if(dir==1){
            idx[2]=idx[0];
            idx[0]=idx[1];
            idx[1]=spare;
        } else if(dir==2){
            idx[1]=idx[0];
            idx[0]=idx[2];
            idx[2]=spare;
        } else if(dir==3){
            idx[4]=idx[0];
            idx[0]=idx[3];
            idx[3]=spare;
        } else {
            idx[3]=idx[0];
            idx[0]=idx[4];
            idx[4]=spare;
        }
        spare = 21 - idx[0] - idx[1] - idx[2] - idx[3] - idx[4];
        if(arr[x][y]==0){
            arr[x][y]=dice[spare];
        } else {
            dice[spare]=arr[x][y];
            arr[x][y]=0;
        }
        cout << dice[idx[0]] << '\n';
    }
}