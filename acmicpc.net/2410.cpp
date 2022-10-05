#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9;
int dp[1000001];
int f(int n){
    if(n==0) return 1;
    if(dp[n]) return dp[n];
    int ret=0;
    for(int i=0; ; ++i){
        int k=(1<<i);
        if(k>n) break;
        if((n-k)%k) break;
        ret+=f((n-k)/k);
        ret%=MOD;
    }
    return dp[n]=ret;
}
int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i) f(i);
    cout << f(N) << '\n';
}