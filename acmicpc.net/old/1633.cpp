#include <bits/stdc++.h>
using namespace std;
int dp[1001][3][16][16];
//dp[i][j][k][w] : i번째 친구에서 j(0:X, 1:흑, 2:백)를 택했을 때
// 누적 k개, 백 w개
int max3(int a, int b, int c){
    return max(max(a,b),c);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n=0;
    while(1){
        int a,b; cin>>a>>b;
        if(cin.eof()) break;
        ++n;
        for(int k=0; k<=15; ++k){
            for(int w=0; w<=15 && k+w<=n; ++w){
                dp[n][0][k][w]=max3(dp[n-1][0][k][w], dp[n-1][1][k][w], dp[n-1][2][k][w]);
                if(k!=0) dp[n][1][k][w]=max3(dp[n-1][0][k-1][w],dp[n-1][1][k-1][w],dp[n-1][2][k-1][w])+a;
                if(w!=0) dp[n][2][k][w]=max3(dp[n-1][0][k][w-1],dp[n-1][1][k][w-1],dp[n-1][2][k][w-1])+b;
            }
        }
    }
    cout << max3(dp[n][0][15][15],dp[n][1][15][15],dp[n][2][15][15]) << '\n';
}