#include <bits/stdc++.h>
using namespace std;
int G[101][101];
int main(){
    int N,M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u,v; cin>>u>>v;
        G[u][v]=1;
        G[v][u]=1;
    }
    int res=0;
    for(int i=1; i<=N; ++i){
        for(int j=i+1; j<=N; ++j){
            for(int k=j+1; k<=N; ++k){
                if(G[i][j] && G[j][k] && G[k][i]){
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
}