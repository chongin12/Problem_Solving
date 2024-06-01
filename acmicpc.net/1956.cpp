#include <bits/stdc++.h>
using namespace std;
int dp[401][401];
const int INF = 987654321;
int res = INF;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int V, E; cin>>V>>E;
    for(int i=1; i<=V; ++i)
        for(int j=1; j<=V; ++j)
            dp[i][j]=INF;
    for(int i=0; i<E; ++i){
        int a, b, c; cin>>a>>b>>c;
        dp[a][b]=c;
    }
    for(int k=1; k<=V; ++k){
        for(int i=1; i<=V; ++i){
            for(int j=1; j<=V; ++j){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i=1; i<=V; ++i) res=min(res,dp[i][i]);
    if(res>=INF) cout << -1 << '\n';
    else cout << res << '\n';
}