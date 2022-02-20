#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int dp[101][101]; // dp[i][j] : i~j 구간에서 겹치지 않는 현의 최대 개수
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a,b; cin>>a>>b; arr[a][b]=1; arr[b][a]=1;
    }
    for(int i=1; i<=100; ++i){
        for(int j=i; j>=1; --j){ // j~i 구간을 갱신 해 줄 것이다.
            for(int k=j; k<i; ++k){
                dp[j][i]=max(dp[j][i], dp[j][k]+dp[k][i]+arr[j][i]);
            }
        }
    }
    cout << dp[1][100] << '\n';
}