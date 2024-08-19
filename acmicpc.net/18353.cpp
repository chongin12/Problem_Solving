#include <bits/stdc++.h>
using namespace std;
int dp[2011], arr[2011];
int main(){
    int N; cin>>N;
    int res=1;
    dp[0]=1;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        dp[i]=1;
        for(int j=0; j<i; ++j){
            if(arr[j]>arr[i]) dp[i]=max(dp[i], dp[j]+1);
        }
        res=max(res,dp[i]);
    }
    cout << N-res << '\n';
}