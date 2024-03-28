#include <bits/stdc++.h>
using namespace std;
const int MN=200001;
int N, M, visited[MN], num[MN], res[MN], In[MN];
vector<int> G[MN], R[MN], V, G2[MN];
vector<vector<int>> S;
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
    S.back().push_back(v);
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
            S.push_back(vector<int>());
            DFS2(it, ++cnt);
        }
    }
    return cnt;
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
    for(const auto &vec: S){
        ++cnt;
        for(auto it:vec) {
            num[it]=cnt;
        }
    }
    for(int i=0; i<M; ++i){
        int s=q[i].first, e=q[i].second;
        if(num[s]!=num[e]){
            In[num[e]]=1;
        }
    }
    // num[i] : i번 노드의 scc 그룹 번호
    int T; cin>>T;
    while(T--){
        int a; cin>>a;
        res[num[a]]=1;
    }
    bool flag=true;
    cnt=0;
    for(int i=0; i<K; ++i){
        if(In[i]==0 && res[i]!=1) flag=false;
        else if(In[i]==0 && res[i]==1) cnt++;
    }
    if(flag) cout << cnt << '\n';
    else cout << "-1\n";
}