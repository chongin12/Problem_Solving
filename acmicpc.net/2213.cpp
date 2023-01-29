#include <bits/stdc++.h>
using namespace std;
vector<int> G[10001];
int arr[10001];
int dp[2][10001]; // 0 : 선택x, 1 : 선택o
void f(int x, int prev){
    dp[1][x]=arr[x];
    for(auto nxt:G[x]){
        if(nxt==prev) continue;
        f(nxt, x);
        dp[0][x]+=max(dp[0][nxt], dp[1][nxt]);
        dp[1][x]+=dp[0][nxt];
    }
}
vector<int> res;
void backtracking(int x, int isSelected, int prev) {
    if(isSelected){
        res.push_back(x);
        for(auto it:G[x]){
            if(it==prev) continue;
            backtracking(it, 0, x);
        }
    }
    else{
        for(auto it:G[x]){
            if(it==prev) continue;
            backtracking(it, dp[0][it]<dp[1][it], x);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>arr[i];
    }
    for(int i=0; i<n-1; ++i){
        int u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    f(1, -1);
    cout << max(dp[0][1], dp[1][1]) << '\n';
    backtracking(1, dp[0][1]<dp[1][1], -1);
    sort(res.begin(), res.end());
    for(auto it:res){
        cout << it << " ";
    }
    cout << '\n';
}