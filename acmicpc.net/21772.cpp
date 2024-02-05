#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int visited[101][101];
int startx, starty;
int res;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int R, C, T;
void f(int x, int y, int acc, int cnt){
    bool flag=false;
    if(arr[x][y]==1 && visited[x][y]==0) {
        flag=true;
        visited[x][y]=1;
        ++acc;
    }
    res=max(res,acc);
    if(cnt<=0) {
        if(flag) {
            visited[x][y]=0;
        }
        return;
    }
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<R && ny>=0 && ny<C && arr[nx][ny]!=3){
            f(nx,ny,acc,cnt-1);
        }
    }
    if(flag) {
        visited[x][y]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>R>>C>>T;
    for(int i=0; i<R; ++i){
        string a; cin>>a;
        for(int j=0; j<C; ++j){
            if(a[j]=='G'){
                startx=i, starty=j;
            }
            else if(a[j]=='S'){
                arr[i][j]=1;
            }
            else if(a[j]=='.'){
                arr[i][j]=2;
            }
            else{
                arr[i][j]=3;
            }
        }
    }
    f(startx, starty, 0, T);
    cout << res << '\n';
}