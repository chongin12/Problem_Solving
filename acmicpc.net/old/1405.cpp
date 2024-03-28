#include <bits/stdc++.h>
using namespace std;
int visited[30][30];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
double p[4];
double L,R,U,D;
double res;
void dfs(int x, int y, double cp, int cnt){
    if(cnt==0) res+=cp;
    else{
        for(int i=0; i<4; ++i){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(!visited[nx][ny]){
                visited[nx][ny]=1;
                dfs(nx,ny,cp*p[i],cnt-1);
                visited[nx][ny]=0;
            }
        }
    }
}
int main(){
    int N; cin>>N;
    cin>>p[3]>>p[1]>>p[2]>>p[0];
    for(int i=0; i<4; ++i) p[i]/=100;
    visited[15][15]=1;
    dfs(15,15,1,N);
    cout << fixed;
    cout.precision(10);
    cout << res << '\n';
}