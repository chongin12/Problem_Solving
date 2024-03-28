#include <bits/stdc++.h>
using namespace std;
const int INF=9999;
int P[201][201];
int D[201][201];
int res[201][201];
int path(int i, int j){
    if(res[i][j]) return res[i][j];
    if(P[i][j]==0) return j;
    return path(i, P[i][j]);
}
int main(){
    int N,M; cin>>N>>M;
    for(int i=0; i<201; ++i){
        for(int j=0; j<201; ++j){
            D[i][j]=INF;
        }
    }
    for(int i=0; i<M; ++i){
        int u, v, w; cin>>u>>v>>w;
        D[u][v]=w;
        D[v][u]=w;
    }
    for(int k=1; k<=N; ++k){
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=N; ++j){
                if(D[i][j] > D[i][k]+D[k][j]){
                    P[i][j]=k;
                    D[i][j]=D[i][k]+D[k][j];
                }
            }
        }
    }
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=N; ++j){
            if(i==j) cout << "- ";
            else cout << path(i, j) << ' ';
        }
        cout << '\n';
    }
}