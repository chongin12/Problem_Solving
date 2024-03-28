#include <bits/stdc++.h>
using namespace std;
const int MN=500001;
int N, M, visited[MN], visitedNum[MN], num[MN], dp[MN], isOutback[MN], toAdd[MN], res;
vector<int> G[MN], R[MN], V, G2[MN];
vector<vector<int>> SCC;
vector<pair<int,int>> q;
void AddEdge(int s, int e){
    G[s].push_back(e);
    R[e].push_back(s);
}
void DFS1(int v){
    visited[v]=-1;
    for(auto it:G[v]) {
        if(!visited[it]) DFS1(it);
    }
    V.push_back(v);
}
void DFS2(int v, int sccNum){
    visited[v]=sccNum;
    SCC.back().push_back(v);
    for(auto it:R[v]){
        if(visited[it]==-1){
            DFS2(it, sccNum);
        }
    }
}
int GetSCC() { // return : Scc 개수
    for(int i=1; i<=N; ++i){
        if(!visited[i]){
            DFS1(i);
        }
    }
    reverse(V.begin(), V.end());
    int cnt=0;
    for(auto it:V){
        if(visited[it]==-1){
            SCC.push_back(vector<int>());
            DFS2(it, ++cnt);
        }
    }
    return cnt;
}
void DFS3(int x){
    visited[x]=1;
    visitedNum[num[x]]=1;
    for(auto it:G[x]){
        if(visited[it]) continue;
        DFS3(it);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(int i=1,s,e; i<=M; ++i){
        cin>>s>>e;
        AddEdge(s,e);
        q.push_back({s,e});
    }  
    int K=GetSCC();
    int cnt=-1;
    for(const auto &vec: SCC){
        ++cnt;
        for(auto it:vec) {
            num[it]=cnt;
        }
    }
    // num[i] : i번 노드의 scc 그룹 번호
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        dp[num[i]]+=a;
    }
    int S,P; cin>>S>>P;
    for(int i=0; i<MN; ++i) visited[i]=0;
    DFS3(S);
    for(int i=1; i<=N; ++i){
        if(!visitedNum[num[i]]) dp[num[i]]=0;
    }
    for(int i=0; i<P; ++i){
        int a; cin>>a;
        isOutback[num[a]]=1;
    }
    for(int i=0; i<MN; ++i) visited[i]=0;
    cnt=-1;
    for(const auto &vec: SCC){
        ++cnt;
        visited[cnt]=1;
        dp[cnt]+=toAdd[cnt];
        if(isOutback[cnt]) res=max(res,dp[cnt]);
        for(auto node:vec) {
            for(auto nxt:G[node]){
                if(visited[num[nxt]]) continue;
                toAdd[num[nxt]]=max(toAdd[num[nxt]],dp[cnt]);
            }
        }
    }
    cout << res << '\n';
}