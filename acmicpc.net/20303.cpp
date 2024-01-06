#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int candy[30001];
vector<int> G[30001];
int visited[30001];
int candies=0, people=0;
vector<pii> v; // {무게, 가치}
int dp[2][3001];
void dfs(int x){
    if(visited[x]) return;
    visited[x]=1;
    people++;
    candies+=candy[x];
    for(auto it:G[x]){
        dfs(it);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K; cin>>N>>M>>K;
    for(int i=1; i<=N; ++i){
        cin >> candy[i];
    }
    for(int i=0; i<M; ++i){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1; i<=N; ++i){
        candies=0, people=0;
        if(!visited[i]) {
            dfs(i);
            v.push_back({people, candies});
        }
    }
    int n=1;
    for(auto it:v){
        int pn=n;
        n=(n+1)%2;
        for(int i=0; i<min(K,it.first); ++i){
            dp[n][i]=dp[pn][i];
        }
        for(int i=it.first; i<K; ++i){
            dp[n][i]=max(dp[pn][i-it.first]+it.second,dp[pn][i]);
        }
    }
    cout << dp[n][K-1] << '\n';
}