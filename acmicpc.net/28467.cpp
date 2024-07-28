#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[401][401]; // dp[i][j] : i~j최소 합치는 비용 합
ll maxC[401][401]; // maxC[i][j] : i~j를 모두 합칠 때 남는 카드
ll arr[401];
int main(){
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        cin>>arr[i];
        maxC[i][i]=arr[i];
    }
    for(ll k=2; k<=N; ++k){
        for(ll i=0; i<N; ++i){
            ll j=i+k-1;
            if(j>=N) break;
            dp[i][j]=arr[i]+dp[i+1][j]+maxC[i+1][j];
            for(ll d=i+1; d<=j; ++d){ // i~d, d+1~j
                dp[i][j]=min(dp[i][j], dp[i][d]+dp[d+1][j]+maxC[i][d]+maxC[d+1][j]);
            }
            maxC[i][j]=max(maxC[i][j-1], arr[j]);
        }
    }
    cout << dp[0][N-1] << '\n';
}