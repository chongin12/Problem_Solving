#include <bits/stdc++.h>
using namespace std;
int visited[1001];
bool flag;
void f(int x, int color, vector<int> G[]){
    visited[x]=color;
    int nxtColor = 3-color;
    for(auto nxt:G[x]){
        if(!visited[nxt]) f(nxt, nxtColor, G);
        else if(visited[nxt]==color){
            flag=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n, m; cin>>n>>m;
        vector<int> G[1001]={};
        flag=true;
        memset(visited, 0, sizeof visited);
        for(int i=0; i<m; ++i){
            int u,v; cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=1; i<=n; ++i){
            if(!visited[i]) f(i, 1, G);
        }
        if(flag) cout << "possible\n";
        else cout << "impossible\n";
    }
}