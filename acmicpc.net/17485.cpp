#include <bits/stdc++.h>
using namespace std;
int dp[2][1001][4]; // dp[i][j][k] : i까지 봤을 때 j 기준으로 k방향으로 움직임
const int INF = 987654321;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            int a; cin>>a;
            // 왼쪽에서 오기 (1)
            if(j==1) dp[(i)%2][j][1]=INF;
            else {
                dp[(i)%2][j][1]=min(dp[(i-1)%2][j-1][2],dp[(i-1)%2][j-1][3])+a;
            }
            // 위쪽에서 오기 (2)
            dp[(i)%2][j][2]=min(dp[(i-1)%2][j][1],dp[(i-1)%2][j][3])+a;

            // 오른쪽에서 오기 (3)
            if(j==M) dp[(i)%2][j][3]=INF;
            else {
                dp[(i)%2][j][3]=min(dp[(i-1)%2][j+1][1],dp[(i-1)%2][j+1][2])+a;
            }
        }
    }
    int res=INF;
    for(int i=1; i<=M; ++i){
        for(int j=1; j<=3; ++j){
            res=min(res,dp[N%2][i][j]);
        }
    }
    cout << res << '\n';
}