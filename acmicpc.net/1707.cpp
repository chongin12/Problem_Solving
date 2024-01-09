#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int V, E; 
vector<int> G[20001];
int visited[20001];
void init(){
    for(int i=0; i<20001; ++i){
        G[i].clear();
        visited[i]=-1;
    }
}
bool bfs(int x){
    queue<pii> q;
    q.push({x,0});
    visited[x]=0;
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        for(auto it:G[cur.first]){
            if(visited[it]==-1){
                q.push({it, cur.second+1});
                visited[it]=cur.second+1;
            }
            else if(visited[it]%2==cur.second%2){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int K; cin>>K;
    for(int t=0; t<K; ++t){
        init();
        cin>>V>>E;
        for(int i=0; i<E; ++i){
            int a, b; cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        bool flag=true;
        for(int i=1; i<=V; ++i){
            if(visited[i]!=-1) continue;
            if(!bfs(i)) {
                flag=false;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}