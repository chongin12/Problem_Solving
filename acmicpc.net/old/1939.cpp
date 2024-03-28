#include <bits/stdc++.h>
using namespace std;
const int INF=1987654321;
vector<pair<int, int> > G[10001];
int visited[10001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u, v, w; cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i=0; i<N; ++i){
        sort(G[i].begin(), G[i].end(), [](pair<int,int> A, pair<int,int> B){
            return A.second>B.second;
        });
    }
    int src,dst; cin>>src>>dst;
    queue<int> q;
    q.push(src);
    visited[src]=INF;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        if(cur==dst) continue;
        for(auto nxt:G[cur]){
            if(visited[nxt.first]<min(visited[cur],nxt.second)){
                visited[nxt.first]=min(visited[cur],nxt.second);
                q.push(nxt.first);
            }
        }
    }
    cout << visited[dst] << '\n';
}