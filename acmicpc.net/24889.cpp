#include <bits/stdc++.h>
using namespace std;
const int MN=200002;
const int cyclePoint=MN-1;
int degree[MN];
vector<int> oriG[MN];
vector<int> G[MN];
bool isInCycle[MN];
int sum[MN];
int P[22][MN]; // P[i][j] : j의 2^i번째 조상
int depth[MN];
void dfs(int v, int prev=-1){
    for(auto it:G[v]){
        if(it!=prev){
            depth[it]=depth[v]+1;
            P[0][it]=v;
            dfs(it,v);
        }
    }
}
int LCA(int u, int v){
    if(depth[u] < depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    for(int i=0; diff; ++i, diff>>=1) {
        if(diff&1) u=P[i][u];
    }
    if(u==v) return u;
    for(int i=21; i>=0; --i){
        if(P[i][u]!=P[i][v]) u=P[i][u], v=P[i][v];
    }
    return P[0][u];
}
int dfs2(int v, int prev=-1){
    for(auto it:G[v]){
        if(it!=prev){
            sum[v]+=dfs2(it,v);
        }
    }
    return sum[v];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    vector<pair<int,int>> input;
    for(int i=0; i<N; ++i){
        int a,b; cin>>a>>b;
        input.push_back({a,b});
        oriG[a].push_back(b);
        oriG[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    queue<int> q;
    for(int i=1; i<=N; ++i){
        if(degree[i]==1) q.push(i);
    }
    while(!q.empty()){
        int cur=q.front(); 
        if(degree[cur]>1) break;
        q.pop();
        for(auto it:oriG[cur]){
            degree[cur]--;
            degree[it]--;
            if(degree[it]==1) q.push(it);
        }
    }
    for(int i=1; i<=N; ++i){
        if(degree[i]>1) {
            isInCycle[i]=true;
            G[i].push_back(cyclePoint);
            G[cyclePoint].push_back(i);
        }
        // cout << "isInCycle["<<i<<"]="<<isInCycle[i] <<'\n';
    }
    for(auto [a,b]:input){
        if(isInCycle[a] && isInCycle[b]) continue;
        G[a].push_back(b);
        G[b].push_back(a);
        // cout << a<<" <-> " << b << '\n';
    }
    dfs(cyclePoint);
    for(int i=1; i<22; ++i){
        for(int j=1; j<MN; ++j){
            P[i][j]=P[i-1][P[i-1][j]];
        }
    }
    while(M--){
        int s,e,w; cin>>s>>e>>w;
        sum[s]+=w;
        sum[e]+=w;
        sum[LCA(s,e)]-=2*w;
    }
    dfs2(cyclePoint);
    int cycleSum=0;
    for(auto it:G[cyclePoint]){
        cycleSum+=sum[it];
        // cout << "sum["<<it<<"]="<<sum[it]<<'\n';
    }
    cycleSum/=2;
    for(auto [a,b]:input){
        int u=a, v=b;
        if(depth[u]<depth[v]) swap(u,v);
        // u가 더 아래
        if(isInCycle[u]) cout << cycleSum << '\n';
        else cout << sum[u] << '\n';
    }
}