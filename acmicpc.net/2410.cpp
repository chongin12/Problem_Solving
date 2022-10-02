#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9;
int dp[1000001];
int main(){
    int N; cin>>N;
    dp[0]=0;
    dp[1]=1;
    int k=1;
    for(int i=2; i<=N; ++i){
        if(i==k*2){
            k*=2;
            dp[i]+=1;
        }
        else{
            dp[i]=dp[k]*dp[i-k];
        }
        dp[i]%=MOD;
        cout << "dp["<<i<<"]="<<dp[i]<<'\n';
    }
    cout << dp[N] << '\n';
}