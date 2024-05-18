#include <bits/stdc++.h>
using namespace std;
double dp[101][2]; // [0] : 좋은 날, [1] : 싫은 날
int main(){
    int N, ch; cin>>N>>ch;
    double a, b, c, d; cin>>a>>b>>c>>d;
    dp[0][ch] = 1.0;
    for(int i=1; i<=N; ++i){
        dp[i][0] = dp[i-1][0]*a + dp[i-1][1]*c;
        dp[i][1] = dp[i-1][0]*b + dp[i-1][1]*d;
    }
    cout <<(int)(dp[N][0]*1000) << '\n';
    cout <<(int)(dp[N][1]*1000) << '\n';
}