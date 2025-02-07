#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int dp[200003][2]; // dp[i][j] : i번째를 j(0:선택안함, 1:선택함)했을 때 점수 최댓값값
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    v.push_back(0);
    v.push_back(0);
    dp[0][0]=v[0];
    dp[0][1]=v[0];
    dp[1][0]=v[0]+v[1];
    dp[1][1]=v[0]+v[1];
    dp[2][0]=dp[1][0]+v[2];
    dp[2][1]=dp[2][0]*2;

    for(int i=3; i<N+2; ++i){
        dp[i][0]=max(dp[i-1][0], dp[i-1][1])+v[i];
        dp[i][1]=max(dp[i-3][0], dp[i-3][1])+(v[i-2]+v[i-1]+v[i])*2;
    }

    // for(int i=0; i<N+2; ++i){
    //     cout << "dp["<<i<<"][0]="<<dp[i][0]<<'\n';
    //     cout << "dp["<<i<<"][1]="<<dp[i][1]<<'\n';
    // }

    cout << max(dp[N+1][0], dp[N+1][1]) << '\n';
}