#include <bits/stdc++.h>
using namespace std;
int dp[11];
int main(){
    int H, Y; cin>>H>>Y;
    dp[0]=H;
    for(int i=1; i<=Y; ++i){
        if(i-1>=0){
            dp[i]=max(dp[i], dp[i-1]*105/100);
        }
        if(i-3>=0){
            dp[i]=max(dp[i], dp[i-3]*120/100);
        }
        if(i-5>=0){
            dp[i]=max(dp[i], dp[i-5]*135/100);
        }
    }
    cout << dp[Y] << '\n';
}