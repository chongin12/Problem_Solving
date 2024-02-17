#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF = 987654321;
vector<pii> G[101];
int visited[101];
int N, M, A, B, C;
int res=INF;
void f(int x, int acc, int maxC){
    if(acc>C) return;
    if(x==B){
        res=min(res, maxC);
        return;
    }
    visited[x]=1;
    for(auto it:G[x]){
        if(!visited[it.first]){
            f(it.first, acc+it.second, max(maxC, it.second));
        }
    }
    visited[x]=0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M>>A>>B>>C;
    for(int i=0; i<M; ++i){
        int a, b, c; cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    f(A, 0, 0);
    if(res==INF) cout << "-1\n";
    else cout << res << '\n';
}