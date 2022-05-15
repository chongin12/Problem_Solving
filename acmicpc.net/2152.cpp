#include <bits/stdc++.h>
using namespace std;
vector<int> G[10001];
vector<int> rG[10001];
vector<int> stk;
int visited[10001];
int dp[10001];
vector<vector<int> > scc;
int grp[10001];
int start, terminal;
void dfs1(int x){
    visited[x]=1;
    for(auto nxt:G[x]){
        if(!visited[nxt]) dfs1(nxt);
    }
    stk.push_back(x);
}
void dfs2(int x){
    visited[x]=1;
    for(auto nxt:rG[x]){
        if(!visited[nxt]) dfs2(nxt);
    }
    scc.back().push_back(x);
}
void dfs3(int x, int cnt){
    visited[x]=1;
    dp[x]=max(dp[x], cnt+(int)scc[x].size());
    if(x<start || x>=terminal){
        return;
    }
    for(auto it:scc[x]){
        for(auto itt:G[it]){
            int nxtGrp=grp[itt];
            if(nxtGrp==x) continue;
            if(visited[nxtGrp]){
                if(dp[nxtGrp]<cnt+scc[x].size()+scc[nxtGrp].size()){
                    dfs3(nxtGrp, cnt+scc[x].size());
                }
            }
            else{
                dfs3(nxtGrp, cnt+scc[x].size());
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, S, T; cin>>N>>M>>S>>T;
    for(int i=0; i<M; ++i){
        int A,B; cin>>A>>B;
        G[A].push_back(B);
        rG[B].push_back(A);
    }
    for(int i=1; i<=N; ++i){
        if(!visited[i]) dfs1(i);
    }
    reverse(stk.begin(), stk.end());
    memset(visited, 0, sizeof(visited));
    for(auto it:stk){
        if(!visited[it]){
            scc.push_back(vector<int>());
            dfs2(it);
        }
    }
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<scc.size(); ++i){
        for(int j=0; j<scc[i].size(); ++j){
            if(scc[i][j]==S) start=i;
            if(scc[i][j]==T) terminal=i;
            grp[scc[i][j]]=i;
        }
    }
    if(start>terminal) {
        cout << "0\n";
    }
    else{
        dp[start]=scc[start].size();
        dfs3(start, 0);
        cout << dp[terminal] << '\n';
    }
}