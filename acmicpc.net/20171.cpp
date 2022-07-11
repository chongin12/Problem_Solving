#include <bits/stdc++.h>
using namespace std;
vector<int> G[100001];
int degree[100001];
int isComplex[100001];
int isErased[100001];
void dfs(int x){
    if(isComplex[x]) return;
    int y=-1;
    for(auto it:G[x]){
        if(isErased[it]) continue;
        y=it;
        break;
    }
    isErased[x]=1;
    degree[x]--;
    if(y==-1) return;
    degree[y]--;
    if(degree[y]==1){
        dfs(y);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    for(int i=1; i<N; ++i){
        int a,b,w; cin>>a>>b>>w;
        G[a].push_back(b);
        G[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    for(int i=0; i<K; ++i){
        int a; cin>>a;
        isComplex[a]=1;
    }
    for(int i=1; i<=N; ++i){
        if(degree[i]==1 && !isComplex[i]){
            dfs(i);
        }
    }
    int cnt=0;
    for(int i=1; i<=N; ++i){
        if(!isErased[i]) cnt++;
    }
    cout << cnt << '\n';
}