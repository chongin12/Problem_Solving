#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[1000];
char Find(ll N, int len){
    ll temp = N/len;
    ll tempIdx=N%len;
    string str="";
    ll k=temp;
    for(int i=1; i<=len; ++i){
        str+=(char)('A'+k/dp[len-i]);
        k=k%dp[len-i];
    }
    return str[N%len];
}
int main(){
    ll N; cin>>N;
    dp[0]=1;
    for(ll i=1; i<15; ++i){
        dp[i]=dp[i-1]*26;
        if(N>=dp[i]*i){
            N-=dp[i]*i;
        }
        else{
            cout << Find(N, i) << '\n';
            break;
        }
    }
}