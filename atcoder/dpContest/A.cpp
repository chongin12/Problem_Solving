#include <bits/stdc++.h>
using namespace std;
int dp[100001];
int main(){
    int N; cin>>N;
    vector<int> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    for(int i=2; i<N; ++i){
        dp[i]=min(dp[i-2]+abs(v[i-2]-v[i]),dp[i-1]+abs(v[i-1]-v[i]));
    }
    cout << dp[N-1] << '\n';
}