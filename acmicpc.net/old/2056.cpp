#include <bits/stdc++.h>
using namespace std;
int dp[100101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    int res=0;
    for(int i=1; i<=N; ++i){
        int a, b; cin>>a>>b;
        int M=0;
        for(int j=0; j<b; ++j){
            int c; cin>>c;
            M=max(M, dp[c]);
        }
        dp[i]=M+a;
        res=max(res,dp[i]);
    }
    cout << res << '\n';
}