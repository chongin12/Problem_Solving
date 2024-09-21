#include <bits/stdc++.h>
using namespace std;
vector<int> G[100001];
int N, S, E;
bool flag=false;
vector<int> path;
void dfs(int x, int prev){
    path.push_back(x);
    if(x==E) {
        flag=true;
        return;
    }
    for(auto it:G[x]){
        if(it==prev) continue;
        if(flag) return;
        dfs(it, x);
    }
    if(flag) return;
    path.pop_back();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>S>>E;
    for(int i=0; i<N-1; ++i){
        int u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(S, -1);
    // for(auto it:path){
    //     cout << it << " ";
    // }
    // cout << '\n';

    int res=1;
    for(int i=0; i<path.size()-1; ++i){
        if(i%2==1 && G[path[i]].size()>2){ res=0; }
    }
    if(res) cout << "First\n";
    else cout << "Second\n";
}