#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int dp1[1000001]; // dp[i] : i까지의 증가수열의 첫 시작 인덱스
int dp2[1000001]; // dp[i] : i까지의 감소수열의 첫 시작 인덱스
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        cin>>arr[i];
        if(i && arr[i]>=arr[i-1]){
            dp1[i]=dp1[i-1];
        }
        else {
            dp1[i]=i;
        }
        
        if(i && arr[i]<=arr[i-1]){
            dp2[i]=dp2[i-1];
        }
        else {
            dp2[i]=i;
        }

    }
    // for(int i=0; i<N; ++i){
    //     cout << "dp1[" << i<<"]="<<dp1[i]<<'\n';
    // }
    // for(int i=0; i<N; ++i){
    //     cout << "dp2[" << i<<"]="<<dp2[i]<<'\n';
    // }
    if(dp1[N-1]==0 || dp2[N-1]==0) cout << "0\n";
    else if((dp1[dp1[N-1]-1]==0 && arr[0]>=arr[N-1]) && (dp2[dp2[N-1]-1]==0 && arr[0]<=arr[N-1])){
        cout << min(dp1[N-1], dp2[N-1]) << '\n';
    }
    else if(dp1[dp1[N-1]-1]==0 && arr[0]>=arr[N-1]){
        cout << dp1[N-1] << '\n';
    }
    else if(dp2[dp2[N-1]-1]==0 && arr[0]<=arr[N-1]){
        cout << dp2[N-1] << '\n';
    }
    else{
        cout << "-1\n";
    }
}