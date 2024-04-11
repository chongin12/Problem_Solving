#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    int res=0;
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        for(int j=0; j<M; ++j){
            dp[i][j]=str[j]-'0';
            res=max(res,dp[i][j]);
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            if(dp[i][j]==0) continue;
            if(i==0 || j==0) continue;
            dp[i][j]=min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
            res=max(res,dp[i][j]);
        }
    }
    cout << res * res << '\n';
}