#include <iostream>
#include <cmath>
#define INF 987654321
#define min(a,b) (a)>(b)?(b):(a)
using namespace std;
int dp[50100]; // i 의 제곱수들 합의 최소개수
int main(){
    int n; cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=0; i<=50000; ++i) dp[i] = INF;
    for(int i=1; i<=223; ++i){
        dp[i*i] = 1;
    }
    for(int i=2; i<=n; ++i){
        for(int j=1; j*j<i; ++j){
            dp[i] = min(dp[i], dp[j*j]+dp[i-j*j]);
        }
    }
    cout << dp[n] << '\n';
}