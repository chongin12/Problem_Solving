#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<int> G[100];
int visited[100];
int minD=987654321;
vector<int> v;

int bfs(int n, int phase){
    queue<pii> q;
    q.push({n,0});
    visited[n]=phase;
    pii cur;
    while(!q.empty()){
        cur = q.front(); q.pop();
        for(auto nxt:G[cur.first]){
            if(visited[nxt]==phase) continue;
            visited[nxt]=phase;
            q.push({nxt, cur.second+1});
        }
    }
    return cur.second;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    while(1){
        int a,b; cin>>a>>b;
        if(a==-1) break;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1; i<=N; ++i){
        int d = bfs(i, i);
        if(d<minD){
            v.clear();
            minD=d;
            v.push_back(i);
        }
        else if(d==minD){
            v.push_back(i);
        }
    }
    cout << minD << " " << v.size() << '\n';
    for(auto it:v){
        cout << it << " ";
    }
    cout << '\n';
}