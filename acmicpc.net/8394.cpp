#include <bits/stdc++.h>
using namespace std;
int dp[3];
int main(){
    int n; cin>>n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; ++i){
        dp[i%3]=(dp[(i-1)%3]+dp[(i-2)%3])%10;
    }
    cout << dp[n%3] << '\n';
}
/*
1 -> 1
2 -> 2
3 -> 3
4 -> 5
*/