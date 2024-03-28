#include <bits/stdc++.h>
using namespace std;
bool dp[10001][3];
int main(){
    int n; cin>>n;
    string temp,T; cin>>temp>>T;
    int a,b; cin>>a>>b;
    string K="";
    K+=temp[a];
    K+=temp[b];
    string S="";
    for(int i=0; i<temp.size(); ++i){
        if(i==a || i==b) continue;
        S+=temp[i];
    }
    dp[0][0]=S[0]==T[0];
    dp[0][1]=K[0]==T[0];
    dp[0][2]=false;
    for(int i=1; i<n; ++i){
        dp[i][0]=dp[i-1][0] && S[i]==T[i];
        dp[i][1]=(dp[i-1][0] && K[0]==T[i])||(dp[i-1][1] && S[i-1]==T[i]);
        dp[i][2]=(dp[i-1][1] && K[1]==T[i])||(dp[i-1][2] && S[i-2]==T[i]);
    }
    cout << (dp[n-1][2]?"YES":"NO") << '\n';
}