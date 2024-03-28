#include <bits/stdc++.h>
using namespace std;
int psum[301][301];
int blockSum(int x1, int y1, int x2, int y2){
    int ret=psum[x2][y2];
    x1--, y1--;
    if(x1>=0){
        ret-=psum[x1][y2];
    }
    if(y1>=0){
        ret-=psum[x2][y1];
    }
    if(x1>=0 && y1>=0){
        ret+=psum[x1][y1];
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int M,N; cin>>M>>N;
    int res=0;
    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            int a; cin>>a;
            if(i==0 && j==0){
                psum[i][j]=a;
            }
            else if(i==0){
                psum[i][j]=psum[i][j-1]+a;
            }
            else if(j==0){
                psum[i][j]=psum[i-1][j]+a;
            }
            else{
                psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+a;
            }
            for(int x=0; x<=10; ++x){
                for(int y=0; y<=10; ++y){
                    if(x*y>10) break;
                    int nx=i-x;
                    int ny=j-y;
                    if(nx<0 || ny<0) break;
                    if(blockSum(nx,ny,i,j)==10) res++;
                }
            }
        }
    }
    cout << res << '\n';
}