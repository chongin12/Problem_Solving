#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int main(){
    int N; cin>>N;
    dp[1]=2;
    dp[2]=1;
    dp[3]=2;
    dp[4]=1;
    for(int i=5; i<=N; ++i){
        if(dp[i-1]+dp[i-3]+dp[i-4]==3) dp[i]=2;
        else dp[i]=1;
    }
    if(dp[N]==1) cout << "SK\n";
    else cout << "CY\n";
}