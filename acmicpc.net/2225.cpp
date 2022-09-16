#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 1000000000;
ll dp[201][201]; // dp[i][j] : i개를 써서 j를 만드는 경우의 수
int main(){
    ll N,K; cin>>N>>K;
    for(int i=0; i<=N; ++i){
        dp[1][i]=1;
    }
    for(int i=2; i<=K; ++i){
        for(int j=0; j<=N; ++j){
            for(int k=0; k<=N-j; ++k){
                dp[i][j+k]+=dp[i-1][j];
                dp[i][j+k]%=MOD;
            }
        }
    }
    cout << dp[K][N] << '\n';
}