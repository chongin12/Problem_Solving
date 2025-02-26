#include <bits/stdc++.h>
using namespace std;
vector<int> G[10001];
int arr[10001];
int visited[10001];
int dfs(int x, int phase){
    visited[x]=phase;
    int ret=1;
    for(auto nxt:G[x]){
        if(visited[nxt]==phase) continue;
        ret+=dfs(nxt, phase);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u, v; cin>>u>>v;
        G[v].push_back(u);
    }
    int res=0;
    for(int i=1; i<=N; ++i){
        arr[i]=dfs(i, i);
        if(arr[i]>res) res=arr[i];
    }
    for(int i=1; i<=N; ++i){
        if(arr[i]==res) cout << i << " ";
    }
    cout << '\n';
}