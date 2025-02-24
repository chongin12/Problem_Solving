#include <bits/stdc++.h>
using namespace std;
vector<int> tetrahedrons = {1};
int dp[300001];
int main(){
    int temp=1;
    for(int i=2;; ++i){
        temp+=i;
        int now = tetrahedrons.back()+temp;
        if(now>300000) break;
        tetrahedrons.push_back(now);
        dp[now]=1;
    }
    int N; cin>>N;
    dp[1]=1;
    for(int i=2; i<=N; ++i){
        if(dp[i]!=0) continue;
        dp[i]=987654321;
        // cout << "i : " << i << '\n';
        for(auto it:tetrahedrons){
            // cout << "  it : " << it << '\n';
            if(i-it<0) break;
            dp[i]=min(dp[i], dp[i-it]+1);
        }
    }
    cout << dp[N] << '\n';
}