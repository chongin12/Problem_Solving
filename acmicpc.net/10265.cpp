#include <bits/stdc++.h>
using namespace std;
const int MN=1001;
int N, K, visited[MN], sccnum[MN];
vector<int> G[MN], R[MN], V, sccG[MN];
pair<int,int> numOfGrp[MN]; // {필수, 나머지}
vector<vector<int>> SCC;
int dp[MN][MN];
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
    sccnum[v]=SCC.size();
    for(auto it:R[v]){
        if(visited[it]==-1){
            DFS2(it, sccNum);
        }
    }
}
void GetSCC() {
    for(int i=1; i<=N; ++i){
        if(!visited[i]){
            DFS1(i);
        }
    }
    reverse(V.begin(), V.end());
    int cnt=0;
    for(auto it:V){
        if(visited[it]==-1){
            SCC.emplace_back();
            DFS2(it, ++cnt);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>K;
    for(int i=1,e; i<=N; ++i){
        cin>>e;
        if(i==e) continue;
        AddEdge(i,e);
    }
    GetSCC();
    for(auto &vec: SCC){
        for(auto it:vec) {
            numOfGrp[sccnum[it]].first++;
        }
        for(auto it:vec) {
            for(auto itt:G[it]){
                if(sccnum[it]!=sccnum[itt]){
                    sccG[sccnum[it]].push_back(sccnum[itt]);
                    numOfGrp[sccnum[itt]].second+=numOfGrp[sccnum[it]].first + numOfGrp[sccnum[it]].second;
                }
            }
        }
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }
    vector<pair<int,int> > v;
    v.emplace_back(0,0);
    for(int i=1; i<=SCC.size(); ++i){
        if(sccG[i].size() == 0) {
            int min_ = numOfGrp[i].first;
            int max_ = numOfGrp[i].first + numOfGrp[i].second;
            v.emplace_back(min_, max_);
        }
    }
    for(int i=1; i<v.size(); ++i){
        for(int j=0; j<v[i].first; ++j){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=v[i].first; j<=K; ++j){
            if(dp[i-1][j] < dp[i-1][j-v[i].first] + v[i].first){
                dp[i][j] = dp[i-1][j-v[i].first] + v[i].second;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << min(dp[v.size()-1][K], K) << '\n';
}