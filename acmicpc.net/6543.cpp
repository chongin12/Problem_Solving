#include <bits/stdc++.h>
using namespace std;
const int MN = 5001;
vector<int> G[MN], rG[MN];
int visited[MN];
vector<vector<int>> SCC;
vector<int> fin;
int SCCNum[MN];
int N,M;
void init(){
    for(int i=0; i<MN; ++i) {
        G[i].clear();
        rG[i].clear();
        visited[i] = 0;
        SCCNum[i]=0;
    }
    SCC.clear();
    fin.clear();
}
void dfs1(int u){
    if(visited[u]) return;
    visited[u]=1;
    for(auto nxt:G[u]){
        dfs1(nxt);
    }
    fin.push_back(u);
}
void dfs2(int u){
    if(visited[u]) return;
    visited[u] = 1;
    SCC.back().push_back(u);
    SCCNum[u] = SCC.size();
    for(auto nxt:rG[u]){
        dfs2(nxt);
    }
}
void makeSCC(){
    for(int i=1; i<=N; ++i){
        if(visited[i]) continue;
        dfs1(i);
    }
    reverse(fin.begin(), fin.end());
    memset(visited, 0, sizeof visited);
    for(auto it:fin){
        if(visited[it]) continue;
        SCC.emplace_back();
        dfs2(it);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        init();
        cin>>N;
        if(N==0) break;
        cin>>M;
        for(int i=0; i<M; ++i){
            int u,v; cin>>u>>v;
            G[u].push_back(v);
            rG[v].push_back(u);
        }
        makeSCC();
        vector<int> res;
        for(auto it:SCC){
            int flag=true;
            for(auto node: it){
                for(auto nxt:G[node]){
                    if(SCCNum[node] != SCCNum[nxt]){
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag){
                for(auto node:it){
                    res.push_back(node);
                }
            }
        }
        sort(res.begin(), res.end());
        for(auto it:res) cout << it << ' ';
        cout << '\n';
    }
}