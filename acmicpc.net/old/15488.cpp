#include <bits/stdc++.h>
using namespace std;
double dp[51][51][51];
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int main(){
    int N,x,y,K; cin>>N>>x>>y>>K;
    dp[0][x][y]=1;
    for(int k=1; k<=K; ++k){
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=N; ++j){
                for(int w=0; w<8; ++w){
                    int nx=i+dx[w];
                    int ny=j+dy[w];
                    if(nx>=1 && nx<=N && ny>=1 && ny<=N){
                        dp[k][nx][ny]+=dp[k-1][i][j]/8;
                    }
                }
            }
        }
    }
    double res=0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            res+=dp[K][i][j];
        }
    }
    cout << fixed << setprecision(10) << res << '\n';
}