#include <bits/stdc++.h>
using namespace std;
const int MN=100001;
int dp[21][MN];
int main(){
    int C, N; cin>>C>>N;
    for(int i=1; i<=N; ++i){
        int a,b; cin>>a>>b;
        for(int j=0; j<a; ++j){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=a; j<=MN; ++j){
            dp[i][j]=max({dp[i-1][j], dp[i-1][j-a]+b, dp[i][j-a]+b});
        }
    }
    for(int i=0; i<=MN; ++i){
        if(dp[N][i]>=C){
            cout << i << '\n';
            return 0;
        }
    }
}