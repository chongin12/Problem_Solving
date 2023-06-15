#include <bits/stdc++.h>
using namespace std;
const int MN = 1001;
vector<int> G[MN*2];
int matching[MN*2];
int visited[MN*2];
void init(){
    for(int i=0; i<MN*2; ++i){
        G[i].clear();
        matching[i]=0;
        visited[i]=0;
    }
}
int bip_match(int u){
    if(visited[u]) return false;
    visited[u]=1;
    for(auto nxt:G[u]){
        if(matching[nxt]==0 || bip_match(matching[nxt])){
            matching[nxt]=u;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        init();
        int N, M; cin>>N>>M;
        for(int i=1; i<=M; ++i){
            int a,b; cin>>a>>b;
            for(int j=a; j<=b; ++j){
                G[i].push_back(j+MN);
            }
        }
        int ret=0;
        for(int i=1; i<=M; ++i){
            memset(visited, 0, sizeof visited);
            if(bip_match(i)) ret++;
        }
        cout << ret << '\n';
    }
}