#include <bits/stdc++.h>
using namespace std;
int visited[200001];
vector<int> G[200001];
using pii=pair<int,int>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u, v; cin>>u>>v; G[u].push_back(v);
    }
    queue<pii> q;
    q.push({1,0});
    visited[1]=1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.first==N) {
            cout << cur.second << '\n';
            return 0;
        }
        for(auto it:G[cur.first]){
            if(!visited[it]) {
                q.push({it, cur.second+1});
                visited[it]=1;
            }
        }
    }
    cout << "-1\n";
}