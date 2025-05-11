#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[101][101];
ll arr[101][101];
int main(){
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        for(ll j=0; j<N; ++j){
            cin>>arr[i][j];
        }
    }
    dp[0][0]=1;
    for(ll i=0; i<N; ++i){
        for(ll j=0; j<N; ++j){
            if(arr[i][j]==0) continue;
            if(i+arr[i][j]<N){
                dp[i+arr[i][j]][j]+=dp[i][j];
            }
            if(j+arr[i][j]<N){
                dp[i][j+arr[i][j]]+=dp[i][j];
            }
        }
    }
    cout << dp[N-1][N-1] << '\n';
}