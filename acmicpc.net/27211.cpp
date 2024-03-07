#include <bits/stdc++.h>
using namespace std;
using pii= pair<int,int>;
int arr[1001][1001];
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

int N, M; 
void dfs(int x, int y){
    if(arr[x][y]) return;
    arr[x][y]=1;
    for(int i=0; i<4; ++i){
        int nx=(x+dx[i]+N)%N;
        int ny=(y+dy[i]+M)%M;
        if(arr[nx][ny]) continue;
        dfs(nx, ny);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(arr[i][j]==0){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout << cnt << '\n';
}