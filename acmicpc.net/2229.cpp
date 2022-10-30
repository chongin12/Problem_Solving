#include <bits/stdc++.h>
using namespace std;
int dp[1001];
int Max[1001];
int Min[1001];//j~i까지 합
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<1001; ++i) Min[i]=987654321,Max[i]=-1;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        for(int j=1; j<=i; ++j){
            Max[j]=max(Max[j], a);
            Min[j]=min(Min[j], a);
        }
        for(int j=1; j<=i; ++j){
            dp[i]=max(dp[i], dp[j-1]+Max[j]-Min[j]);
        }
    }
    cout << dp[N] << '\n';
}