#include <bits/stdc++.h>
using namespace std;
int indegree[100001];
vector<int> G[100001];
int visited[100001];
bool dfs(int x){
    visited[x]=1;
    if(x==1) return true;
    for(auto nxt:G[x]){
        if(visited[nxt]) continue;
        if(dfs(nxt)) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u,v; cin>>u>>v;
        G[v].push_back(u);
        indegree[u]++;
    }
    int S; cin>>S;
    for(int i=0; i<S; ++i){
        int s; cin>>s;
        if(s==1) visited[s]=1;
        G[s].clear();
    }
    for(int i=1; i<=N; ++i){
        if(indegree[i]==0 && visited[i]==0){
            if(dfs(i)){
                cout << "yes\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}