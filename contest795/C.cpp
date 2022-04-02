#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MOD=1000000007;
ll dp[5][200001];
int main(){
    int N; cin>>N;
    string str; cin>>str;
    for(int i=1; i<=str.size(); ++i){
        char ch=str[i-1];
        for(int j=0; j<4; ++j){
            dp[j][i]=dp[j][i-1];
        }
        if(ch=='W'){
            dp[0][i]=dp[0][i-1]+1;
            dp[0][i]%=MOD;
        }
        else if(ch=='H'){
            dp[1][i]=dp[0][i-1]+dp[1][i-1];
            dp[1][i]%=MOD;
        }
        else if(ch=='E'){
            dp[3][i]=dp[2][i-1]+dp[3][i-1]*2;
            dp[3][i]%=MOD;
            dp[2][i]=dp[1][i-1]+dp[2][i-1];
            dp[2][i]%=MOD;
        }
    }
    cout << dp[3][str.size()]%MOD << '\n';
}