#include <bits/stdc++.h>
using namespace std;
int dp[26];
int main(){
    int N; cin>>N;
    int res=0;
    for(int i=1; i<=N; ++i){
        int a, b, c; cin>>a>>b>>c;
        if(i<=2){
            dp[i]=c;
        }
        else{
            dp[i]=max(dp[i-2],dp[i-3])+c;
        }
        res=max(res,dp[i]);
    }
    cout << res << '\n';
}