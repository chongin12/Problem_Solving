#include <bits/stdc++.h>
using namespace std;
vector<int> G[100001];
int visited[100001];
int res[100001];
int cnt=1;
void f(int x) {
    visited[x]=1;
    res[x]=cnt++;
    for(auto it:G[x]){
        if(!visited[it]) f(it);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, R; cin>>N>>M>>R;
    for(int i=0; i<M; ++i){
        int u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1; i<=N; ++i){
        sort(G[i].begin(), G[i].end(), greater<int>());
    }
    f(R);
    for(int i=1; i<=N; ++i){
        cout << res[i] << '\n';
    }
}