#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000;
int dp[5002]; // dp[i] : i번째까지 완료했을 때 나올 수 있는 경우의 수
int main(){
    string str; cin>>str;
    dp[0]=1;
    dp[1]=1;
    if(str[0]=='0'){
        cout << "0\n";
        return 0;
    }
    for(int i=1; i<str.size(); ++i){
        if(str[i]!='0') dp[i+1]+=dp[i];
        if(str[i-1]=='1'){
            dp[i+1]+=dp[i-1];
            dp[i+1]%=MOD;
        }
        else if(str[i-1]=='2' && str[i]<='6'){
            dp[i+1]+=dp[i-1];
            dp[i+1]%=MOD;
        }
        else if(str[i]=='0' && str[i-1]>='3'){
            cout << "0\n";
            return 0;
        }
    }
    cout << dp[str.size()] << '\n';
}