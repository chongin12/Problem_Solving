#include <bits/stdc++.h>
using namespace std;
vector<int> G[100001];
int arr[100001];
void dfs(int x, int prev=-1){
    arr[x]=1;
    for(auto it:G[x]){
        if(it==prev) continue;
        dfs(it,x);
        arr[x]+=arr[it];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, R, Q; cin>>N>>R>>Q;
    for(int i=0; i<N-1; ++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(R);
    while(Q--){
        int U; cin>>U;
        cout << arr[U] << '\n';
    }
}