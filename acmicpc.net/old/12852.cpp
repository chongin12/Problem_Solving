#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
int P[1000001];
int main(){
    int X; cin>>X;
    dp[1]=0;
    for(int i=2; i<=X; ++i){
        dp[i]=dp[i-1]+1; // 3번 연산 선택
        P[i]=i-1;
        if(i%2==0 && dp[i]>dp[i/2]+1) { // 2번 연산 선택
            dp[i]=dp[i/2]+1;
            P[i]=i/2;
        }
        if(i%3==0 && dp[i]>dp[i/3]+1) { // 1번 연산 선택
            dp[i]=dp[i/3]+1;
            P[i]=i/3;
        }
    }
    cout << dp[X] << '\n';
    int k=X;
    for(int i=0; i<dp[X]; ++i){
        cout << k << " ";
        k=P[k];
    }
    cout << 1 << '\n';
}