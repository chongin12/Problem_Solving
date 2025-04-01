#include <bits/stdc++.h>
using namespace std;
vector<int> G[401];
int dp[401][401];
const int INF = 987654321;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<401; ++i){
        for(int j=0; j<401; ++j){
            dp[i][j]=INF;
        }
    }
    int n, k; cin>>n>>k;
    for(int i=0; i<k; ++i){
        int u, v; cin>>u>>v;
        G[v].push_back(u);
        dp[v][u]=1;
    }
    for(int k=1; k<=n; ++k){
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                if(i==j) continue;
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    int q; cin>>q;
    while(q--){
        int a, b; cin>>a>>b;
        if(dp[a][b]!=INF){
            cout << "1\n";
        }
        else if(dp[b][a]!=INF){
            cout << "-1\n";
        }
        else {
            cout << "0\n";
        }
    }
}