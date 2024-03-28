#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(){
    string str; cin>>str;
    int N=str.size();
    for(int k=1; k<=N; ++k){//문자 k개를 본다.
        for(int i=0; i<N-k+1; ++i){
            int j=i+k-1;
            //i ~ j 탐색
            if(k==1) dp[i][j]=1;
            else if(k==2){
                if(str[i]==str[j]) dp[i][j]=3;
                else dp[i][j]=2;
            }
            else{
                dp[i][j]=-dp[i+1][j-1]+dp[i][j-1]+dp[i+1][j];
                if(str[i]==str[j]){
                    dp[i][j]+=dp[i+1][j-1]+1;
                }
            }
            // cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
        }
    }
    cout << dp[0][N-1] << '\n';
}