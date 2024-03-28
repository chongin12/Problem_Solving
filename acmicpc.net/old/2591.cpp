#include <bits/stdc++.h>
using namespace std;
int dp[50];
int main(){
    string str; cin>>str;
    str=" "+str;
    dp[0]=1;
    for(int i=1; i<str.size(); ++i){
        bool flag=true;
        if(str[i]!='0') {
            dp[i]=dp[i-1];
            flag=false;
        }
        if(str[i-1]!='0' && (str[i-1]-'0')*10+str[i]-'0'<=34){
            dp[i]+=dp[i-2];
            flag=false;
        }
        if(flag) {
            cout << "0\n";
            return 0;
        }
        // cout << "dp["<<i<<"]="<<dp[i]<<'\n';
    }
    cout << dp[str.size()-1] << '\n';
}