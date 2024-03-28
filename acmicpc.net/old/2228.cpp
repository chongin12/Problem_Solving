#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101]; // dp[i][j][k] : i~j에서 구간 k개 선택해서 만들 수 있는 최대값
int arr[101];
int psum[101];
const int INF=987654321;
void init() {
    for(int i=0; i<101; ++i){
        for(int j=0; j<101; ++j){
            for(int k=0; k<101; ++k){
                dp[i][j][k]=-INF;
            }
        }
    }
}
int prefixSum(int i, int j){
    if(i==0) return psum[j];
    else return psum[j]-psum[i-1];
}
int main(){
    init();
    int N,M; cin>>N>>M;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        dp[i][i][1]=arr[i];
        if(i==0) psum[i]=arr[i];
        else psum[i]=psum[i-1]+arr[i];
    }
    for(int w=1; w<=N; ++w){
        for(int i=0; i<N-w+1; ++i){
            int j=i+w-1;
            dp[i][j][1]=max(dp[i][j][1], prefixSum(i, j));
            for(int range=1; range<=min(M,(w+1)/2); ++range){
                // dp[i][j][range] 채울 예정
                int &toFill = dp[i][j][range];
                if(i!=j) toFill=max(toFill, dp[i][j-1][range]);
                if(i!=j) toFill=max(toFill, dp[i+1][j][range]);
                for(int lrange=1; lrange<range; ++lrange){
                    int rrange=range-lrange;
                    for(int k=i; k+2<=j; ++k){
                        // i~k, k+2~j
                        // 왼쪽 i~k를 lrange 구간만큼 선택
                        // 가운데 하나 비워주고
                        // 오른쪽 k+2~j를 rrange 구간만큼 선택
                        toFill=max(toFill, dp[i][k][lrange]+dp[k+2][j][rrange]);
                    }
                }
                //cout << "dp["<<i<<"]["<<j<<"]["<<range<<"]="<<dp[i][j][range]<<'\n';
            }
        }
    }
    cout << dp[0][N-1][M] << '\n';
}