#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
ll dp[100];
int main(){
    ll N; cin>>N;
    dp[0]=0;
    ll i;
    for(i=1; i<29; ++i){
        dp[i]=dp[i-1]*2+i+2;
    }
    for(;i>=1;--i){
        if(dp[i-1]>=N) continue;
        N-=dp[i-1];
        if(N==1){
            cout << "m\n";
            break;
        }
        else if(N<=i+2){
            cout << "o\n";
            break;
        }
        N-=i+2;
    }
}