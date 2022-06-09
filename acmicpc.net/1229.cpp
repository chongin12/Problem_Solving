#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
int cache[800];
int f(int x){
    if(x==0 || dp[x]) return dp[x];
    int ret=6;
    for(int i=0; i<800; ++i){
        if(cache[i]>x) break;
        if(cache[i]*6<x) continue;
        ret=min(ret, 1+f(x-cache[i]));
    }
    return dp[x]=ret;
}
int main(){
    int N; cin>>N;
    cache[0]=1;
    int k=5;
    for(int i=1; i<800; ++i){
        cache[i]=cache[i-1]+k;
        k+=4;
    }
    
    dp[0]=0;
    dp[1]=1;
    cout << f(N) << '\n';
}