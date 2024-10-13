#include <bits/stdc++.h>
using namespace std;
int arr[11][11];
int dp[11][2048];
int N;
int tsp(int cur, int mask){
    if(mask==(1<<N)-1) {
        if(arr[cur][0]==0) return 987654321;
        return arr[cur][0];
    }
    if(dp[cur][mask]) return dp[cur][mask];
    int ret=987654321;
    for(int i=0; i<N; ++i){
        if(mask & (1<<i) || arr[cur][i]==0) continue;
        ret=min(ret,tsp(i, mask | (1<<i))+arr[cur][i]);
    }
    return dp[cur][mask]=ret;
}
int main(){
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            cin>>arr[i][j];
        }
    }
    cout << tsp(0, 1) << '\n';
}