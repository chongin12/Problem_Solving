#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 1e9+7;
ll dp[100001];
int main(){
    dp[0]=1;
    for(int i=1; i<100001; ++i){
        dp[i]=dp[i-1]*2%MOD;
    }
    string str; cin>>str;
    ll res=0;
    for(int i=0; i<str.size(); ++i){
        if(str[i]=='O') {
            res=(res+dp[i])%MOD;
        }
    }
    cout << res << '\n';
}