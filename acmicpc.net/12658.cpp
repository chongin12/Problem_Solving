#include <bits/stdc++.h>
using namespace std;
const int MN = 101;
int arr[MN][MN];
int dp[MN][MN];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int H, W;
int cnt=0;
void init(){
    cnt=0;
    for(int i=0; i<MN; ++i){
        for(int j=0; j<MN; ++j){
            dp[i][j]=-1;
        }
    }
}
int f(int x, int y){
    if(dp[x][y]!=-1) return dp[x][y];
    int minV=arr[x][y], minnx=-1, minny=-1;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<H && ny>=0 && ny<W && arr[nx][ny]<minV){
            minV = arr[nx][ny];
            minnx=nx;
            minny=ny;
        }
    }
    if(minV==arr[x][y]) {
        return dp[x][y]=cnt++;
    } else {
        return dp[x][y] = f(minnx, minny);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        cout << "Case #"<<t<<":\n";
        init();
        cin>>H>>W;
        for(int i=0; i<H; ++i){
            for(int j=0; j<W; ++j){
                cin>>arr[i][j];
            }
        }
        for(int i=0; i<H; ++i){
            for(int j=0; j<W; ++j){
                f(i,j);
            }
        }
        for(int i=0; i<H; ++i){
            for(int j=0; j<W; ++j){
                cout << (char)('a'+dp[i][j]) << ' ';
            }
            cout << '\n';
        }
    }
}