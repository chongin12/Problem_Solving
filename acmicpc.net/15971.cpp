#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> G[100001];
int visited[100001];
int a, b;
vector<int> temp;
void dfs(int x) {
    if(visited[x]) return;
    visited[x]=1;
    if(x==b) {
        int maxVal = 0;
        int cnt=0;
        for(auto it:temp){
            maxVal = max(maxVal, it);
            cnt+=it;
        }
        cout << cnt-maxVal << '\n';
        return;
    }
    for(auto it:G[x]){
        if(visited[it.first]) continue;
        temp.push_back(it.second);
        dfs(it.first);
        temp.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    cin>>a>>b;
    for(int i=0; i<N-1; ++i){
        int u, v, w; cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs(a);
}