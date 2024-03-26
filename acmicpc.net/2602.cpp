#include <bits/stdc++.h>
using namespace std;
int dp[101][21][2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    str = " " + str;
    string s1, s2; cin>>s1>>s2;
    s1 = " " + s1;
    s2 = " " + s2;
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    for(int i=1; i<s1.size(); ++i){
        if(str[1]==s1[i]){
            dp[i][1][0]=1;
        }
        if(str[1]==s2[i]){
            dp[i][1][1]=1;
        }
        for(int j=2; j<min((int)str.size(), i+1); ++j) {
            if(str[j]==s1[i]){
                // dp[i][j][0] 가능.
                for(int w=0; w<i; ++w){
                    dp[i][j][0]+=dp[w][j-1][1];
                }
            }
            // cout << "dp["<<i<<"]["<<j<<"][0]="<<dp[i][j][0] << '\n';

            if(str[j]==s2[i]){
                // dp[i][j][1] 가능.
                for(int w=0; w<i; ++w){
                    dp[i][j][1]+=dp[w][j-1][0];
                }
            }
            // cout << "dp["<<i<<"]["<<j<<"][1]="<<dp[i][j][1] << '\n';
        }
    }
    int res=0;
    for(int i=1; i<s1.size(); ++i){
        res+=dp[i][str.size()-1][0];
        res+=dp[i][str.size()-1][1];
    }
    cout << res << '\n';
}