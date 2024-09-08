#include <bits/stdc++.h>
using namespace std;
double dp[10001]; // dp[i] : i로 끝나는 배열 중 가장 큰 것
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    double res=0;
    for(int i=1; i<=N; ++i){
        double a; cin>>a;
        if(i==1) dp[i]=a;
        else {
            if(dp[i-1]*a<a){
                dp[i]=a;
            } else {
                dp[i]=dp[i-1]*a;
            }
        }
        res=max(res,dp[i]);
    }
    cout.precision(3);
    cout << fixed;
    cout << res << '\n';
}