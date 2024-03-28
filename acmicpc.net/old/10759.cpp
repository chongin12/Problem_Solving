#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
string arr[501];
int dp[2][501][501];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
    }
    for(int i=0; i<N; ++i){
        dp[0][i][i]=1;
    }
    for(int phase=1; phase<N; ++phase){
        for(int i=0; i<N-phase; ++i){
            for(int j=0; j<N-phase; ++j){
                dp[phase%2][i][j]=0;
            }
        }
        for(int j=0; j<N-phase; ++j){
            for(int k=0; k<N-phase; ++k){
                int jx=j, jy=N-1-phase-jx;
                int kx=k+phase, ky=N-1+phase-kx;
                if(jx>kx || jy>ky) continue;
                if(arr[jx][jy]==arr[kx][ky]){
                    // 4가지 경우가 있음.
                    // dp[phase-1][j][k]
                    if(jx<=kx-1 && jy+1<=ky)
                        dp[phase%2][j][k]+=dp[(phase-1)%2][j][k];
                    dp[phase%2][j][k]%=MOD;
                    // dp[phase-1][j+1][k]
                    if(jx+1<=kx-1 && jy<=ky)
                        dp[phase%2][j][k]+=dp[(phase-1)%2][j+1][k];
                    dp[phase%2][j][k]%=MOD;
                    // dp[phase-1][j][k+1]
                    if(jx<=kx && jy+1<=ky-1)
                        dp[phase%2][j][k]+=dp[(phase-1)%2][j][k+1];
                    dp[phase%2][j][k]%=MOD;
                    // dp[phase-1][j+1][k+1]
                    if(jx+1<=kx && jy<=ky-1)
                        dp[phase%2][j][k]+=dp[(phase-1)%2][j+1][k+1];
                    dp[phase%2][j][k]%=MOD;
                }
            }
        }
    }
    cout << dp[(N-1)%2][0][0]%MOD << '\n';
}