#include <bits/stdc++.h>
using namespace std;
const int MOD = 900528;
int dp[1000001];
map<char, int> m;
int main(){
    string str; cin>>str;
    for(int i=str.size()-1; i>=0; --i){
        m[str[i]]=i;
    }
    string cyper; cin>>cyper;
    dp[0]=1;
    int res=1;
    for(int i=1; i<cyper.size(); ++i){
        dp[i]=dp[i-1]*str.size();
        dp[i]%=MOD;
        res+=dp[i];
        res%=MOD;
    }
    for(int i=0; i<cyper.size(); ++i){
        res+=dp[(cyper.size()-i-1)]*m[cyper[i]];
        res%=MOD;
    }
    cout << res << '\n';
}