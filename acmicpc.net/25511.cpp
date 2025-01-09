#include <bits/stdc++.h>
using namespace std;
vector<int> G[100001];
int goal;
int res=0;
void dfs(int x, int acc){
    if(x==goal) {
        res=acc;
        return;
    }
    for(auto it:G[x]){
        dfs(it, acc+1);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, K; cin>>N>>K;
    for(int i=0; i<N-1; ++i){
        int p, c; cin>>p>>c;
        G[p].push_back(c);
    }
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        if(a==K){
            goal=i;
            dfs(0, 0);
            cout << res << '\n';
            return 0;
        }
    }
}