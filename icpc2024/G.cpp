#include <bits/stdc++.h>
using namespace std;
int par[100001];
void init(){
    for(int i=0; i<100001; ++i){
        par[i]=i;
    }
}
int Find(int x){
    if(par[x]==x) return x;
    return par[x]=Find(par[x]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    par[a]=b;
}
struct Node {
    int u, v, w;
};
vector<Node> edges;
vector<Node> original;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int N,M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u, v, w; cin>>u>>v>>w;
        edges.push_back(Node({u,v,w}));
        original.push_back(Node({u,v,w}));
    }
    sort(edges.begin(), edges.end(), [](Node a, Node b){
        return a.w < b.w;
    });
    
}