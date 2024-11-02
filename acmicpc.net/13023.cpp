#include <bits/stdc++.h>
using namespace std;
vector<int> G[2011];
int res=0;
int visited[2011];
void f(int cur, int depth) {
    if(depth==4) {
        res=1;
        return;
    }
    for(auto nxt:G[cur]){
        if(res) return;
        if(visited[nxt]) continue;
        visited[nxt]=1;
        f(nxt, depth+1);
        visited[nxt]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0; i<N; ++i){
        // memset(visited, 0, sizeof visited);
        visited[i]=1;
        f(i, 0);
        visited[i]=0;
        if(res) break;
    }
    cout << res << '\n';
}