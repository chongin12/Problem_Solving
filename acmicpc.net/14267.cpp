#include <bits/stdc++.h>
using namespace std;
vector<int> G[100001];
int arr[100001];
void dfs(int x, int acc, int prev){
    acc+=arr[x];
    arr[x]=acc;
    for(auto it:G[x]){
        if(it==prev) continue;
        dfs(it, acc, x);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin>>N>>M;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        if(i==1) continue;
        G[a].push_back(i);
    }
    for(int i=1; i<=M; ++i){
        int a,b; cin>>a>>b;
        arr[a]+=b;
    }
    dfs(1, 0, -1);
    for(int i=1; i<=N; ++i){
        cout << arr[i] << " ";
    }
    cout << '\n';
}