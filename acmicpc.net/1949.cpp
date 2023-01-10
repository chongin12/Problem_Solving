#include <bits/stdc++.h>
using namespace std;
int arr[10001];
vector<int> G[10001];
int dp[2][10001]; // 0 : 선택안함, 1 : 선택함
void dfs(int x, int prev=-1){
    dp[1][x]=arr[x];
    for(auto it:G[x]){
        if(it==prev) continue;
        dfs(it, x);
        dp[0][x]+=max(dp[0][it],dp[1][it]);
        dp[1][x]+=dp[0][it];
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=1; i<=N; ++i) cin>>arr[i];
    for(int i=0; i<N-1; ++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[0][1],dp[1][1]) << '\n';
}