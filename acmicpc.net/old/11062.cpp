#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001]; // dp[i][j] : i~j카드들이 있을 때 근우가 얻는 최대 점수
int arr[1001];
void init() {
    for(int i=0; i<1001; ++i){
        for(int j=0; j<1001; ++j){
            dp[i][j]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        init();
        int N; cin>>N;
        for(int i=1; i<=N; ++i){
            cin>>arr[i];
        }
        for(int k=1; k<=N; ++k){
            for(int i=1; i<=N; ++i){
                int j=i+k-1;
                if(i>j || j>N) continue;
                // i~j 범위 보는 중
                // k가 N이면 근우, N-1이면 명우, ...
                if((N-k)%2==0){ // 근우 선택중
                    dp[i][j]=max(dp[i][j-1]+arr[j], dp[i+1][j]+arr[i]);
                }
                else { // 명우 선택중
                    dp[i][j]=min(dp[i][j-1], dp[i+1][j]);
                }
                // cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
            }
        }
        cout << dp[1][N] << '\n';
    }
}