#include <bits/stdc++.h>
using namespace std;
int dp[100001][2];
// dp[i][0] : 자기를 무조건 포함하는, 연속된 수열의 합. 제거 없음.
// dp[i][1] : 자기를 무조건 포함하는, 연속된 수열의 합. 제거 있음.
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int res=-987654321;
    for(int i=0; i<n; ++i){
        int a; cin>>a;
        if(!i){
            dp[i][0]=a;
            dp[i][1]=0;
            res=a;
        }
        else{
            if(dp[i-1][0]<0) dp[i][0]=a;
            else dp[i][0]=dp[i-1][0]+a;

            dp[i][1]=max(dp[i-1][0], dp[i-1][1]+a);
            res=max({res, dp[i][0], dp[i][1]});
        }
    }
    cout << res << '\n';
}