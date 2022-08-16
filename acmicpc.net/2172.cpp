#include <bits/stdc++.h>
using namespace std;
int dp[21][21][21][21][21];
int arr[21][21];
int N,L;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
void f(int startL){
    for(int l=startL; l<=L; l+=2){
        for(int x1=0; x1<N; ++x1){
            for(int y1=0; y1<N; ++y1){
                for(int x2=0; x2<N; ++x2){
                    for(int y2=0; y2<N; ++y2){
                        for(int i=0; i<8; ++i){
                            int nx1=x1+dx[i];
                            if(nx1<0 || nx1>=N) continue;
                            int ny1=y1+dy[i];
                            if(ny1<0 || ny1>=N) continue;
                            for(int j=0; j<8; ++j){
                                int nx2=x2+dx[j];
                                if(nx2<0 || nx2>=N) continue;
                                int ny2=y2+dy[j];
                                if(ny2<0 || ny2>=N) continue;
                                if(arr[nx1][ny1]==arr[nx2][ny2]){
                                    dp[nx1][ny1][nx2][ny2][l]+=dp[x1][y1][x2][y2][l-2];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>L;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
        }
    }
    if(L%2){
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                dp[i][j][i][j][1]=1;
            }
        }
        f(3);
    }
    else{
        for(int i=0; i<N; ++i){
            for(int j=0; j<N; ++j){
                for(int k=0; k<8; ++k){
                    int nx=i+dx[k];
                    if(nx<0 || nx>=N) continue;
                    int ny=j+dy[k];
                    if(ny<0 || ny>=N) continue;
                    if(arr[i][j]==arr[nx][ny]){
                        dp[i][j][nx][ny][2]+=1;
                    }
                }
            }
        }
        f(4);
    }
    int res=0;
    for(int x1=0; x1<N; ++x1){
        for(int y1=0; y1<N; ++y1){
            for(int x2=0; x2<N; ++x2){
                for(int y2=0; y2<N; ++y2){
                    res+=dp[x1][y1][x2][y2][L];
                }
            }
        }
    }
    cout << res << '\n';
}