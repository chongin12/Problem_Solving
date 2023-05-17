#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;
const int INF = 987654321;
int dist[101];
int r[101];
vector<int> rG[101];
int canReach[101];
int visited[101];
int n, m;
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w):u(u),v(v),w(w){}
};
vector<Edge> V;
void init(){
    for(int i=0; i<101; ++i){
        dist[i] = INF;
    }
    r[1]=1;
    dist[1]=0;
}
void dfs(int X){
    visited[X]=1;
    canReach[X]=1;
    for(auto it:rG[X]){
        if(!visited[it]) dfs(it);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<m; ++i){
        int u, v, w; cin>>u>>v>>w;
        rG[v].push_back(u);
        V.emplace_back(u,v,-w);
    }
    init();
    dfs(n);
    for(int i=0; i<n-1; ++i){
        for(auto it:V){
            if(dist[it.u]==INF) continue;
            if(dist[it.v] > dist[it.u]+it.w){
                dist[it.v] = dist[it.u]+it.w;
                r[it.v]=it.u;
            }
        }
    }
    int flag=true;
    for(auto it:V){
        if(dist[it.u]==INF) continue;
        if(dist[it.v] > dist[it.u]+it.w){
            dist[it.v] = dist[it.u]+it.w;
            r[it.v]=it.u;
            if(canReach[it.u]) flag=false;
        }
    }
    if(!flag){
        cout << "-1\n";
        return 0;
    }
    int k=n;
    vector<int> tmp;
    while(1){
        tmp.push_back(k);
        if(k==1) break;
        k=r[k];
    }
    reverse(tmp.begin(), tmp.end());
    for(auto it:tmp) cout << it << " ";
    cout << '\n';

}