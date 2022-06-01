#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int C,E; cin>>C>>E;
    if(C+E>=N*N) {
        cout << "-1\n";
        return 0;
    }
    for(int i=0; i<=200; ++i){
        int x=0, y=i;
        if(C<=0) break;
        while(y>=0){
            if(C<=0) break;
            if(!(x>=N || y>=N)){
                arr[x][y]=1;
                C--;
            }
            x++, y--;
        }
    }
    for(int i=200; i>=0; --i){
        int x=i, y=0;
        if(E<=0) break;
        while(x>=0){
            if(E<=0) break;
            if(!(x>=N || y>=N)){
                arr[x][y]=2;
                E--;
            }
            x--, y++;
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(arr[i][j]==0) continue;
            for(int k=0; k<4; ++k){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0 && nx<N && ny>=0 && ny<N){
                    if(arr[nx][ny]==0) continue;
                    if(arr[nx][ny]!=arr[i][j]){
                        cout << "-1\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "1\n";
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cout << arr[i][j];
        }
        cout << '\n';
    }
}