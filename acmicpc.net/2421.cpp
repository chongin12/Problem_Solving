#include <bits/stdc++.h>
using namespace std;
const int MN = 1000001;
int isErased[MN];
int dp[1000][1000]; // dp[i][j] = 왼쪽에 i, 오른쪽에 j만큼 있을 때 누적된 최대 횟수
int main(){
    int N; cin>>N;
    for(int i=2; i*i<MN; ++i){
        if(isErased[i]) continue;
        for(int j=i*i; j<MN; j+=i){
            isErased[j]=1;
        }
    }
    for(int i=1; i<=999; ++i){
        for(int j=1; j<=999; ++j){
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            int n;
            if(i==1 && j==1) n=4;
            else if(j>=1&&j<10) n=i*10+j;
            else if(j>=10&&j<100) n=i*100+j;
            else if(j>=100&&j<1000) n=i*1000+j;
            if(!isErased[n]) dp[i][j]+=1;
        }
    }
    cout << dp[N][N] << '\n';
}