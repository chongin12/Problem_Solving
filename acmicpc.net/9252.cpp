#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[4001][4001];
string res = "";

int main(){
    string a, b; cin >> a >> b;
    for(int i=0; i<a.size(); ++i){
        for(int j=0; j<b.size(); ++j){
            if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
    int i=a.size(), j=b.size();
    while(1) {
        if(dp[i][j] == 0) break;
        if(dp[i-1][j] == dp[i][j]){
            i-=1;
            continue;
        }
        if(dp[i][j-1] == dp[i][j]) {
            j-=1;
            continue;
        }
        res+=a[i-1];
        i-=1; j-=1;
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
}