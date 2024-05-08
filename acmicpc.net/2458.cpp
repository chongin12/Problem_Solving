#include <bits/stdc++.h>
using namespace std;
vector<int> G[501], rG[501];
int visited[501];
void init(){
    memset(visited, 0, sizeof visited);
}
int dfs(int x){
    int ret=1;
    visited[x]=1;
    for(auto it:G[x]){
        if(visited[it]) continue;
        ret+=dfs(it);
    }
    return ret;
}
int rdfs(int x){
    int ret=1;
    visited[x]=1;
    for(auto it:rG[x]){
        if(visited[it]) continue;
        ret+=rdfs(it);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    int res=0;
    for(int i=1; i<=N; ++i){
        init();
        int a = dfs(i);
        init();
        int b = rdfs(i);
        res+=(a+b-1)==N;
    }
    cout << res << '\n';
}