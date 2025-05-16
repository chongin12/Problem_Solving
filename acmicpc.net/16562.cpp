#include <bits/stdc++.h>
using namespace std;
vector<int> G[10001];
int visited[10001];
vector<int> v={0};
int dfs(int u){
    visited[u]=1;
    int ret=v[u];
    for(auto nxt:G[u]){
        if(!visited[nxt]){
            ret=min(ret,dfs(nxt));
        }
    }
    return ret;
}
int main(){
    int N, M, K; cin>>N>>M>>K;
    
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    for(int i=0; i<M; ++i){
        int u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int cnt=0;
    for(int i=1; i<=N; ++i){
        if(visited[i]) continue;
        cnt+=dfs(i);
    }
    if(cnt>K) cout << "Oh no\n";
    else cout << cnt << '\n';
}