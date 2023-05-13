#include <bits/stdc++.h>
using namespace std;
const int INF = 1987654321;
int p[10001];
int w[10001];
struct Edge {
    int u,v,w;
    Edge(int u, int v, int w):u(u),v(v),w(w) {}
};
void init(){
    for(int i=0; i<10001; ++i){
        p[i]=i;
        w[i]=INF;
    }
}
int Find(int x){
    if(p[x]==x) return x;
    return p[x]=Find(p[x]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    p[b]=a;
}
int main(){
    init();
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M; cin>>N>>M;
    vector<Edge> v;
    for(int i=0; i<M; ++i){
        int A,B,C; cin>>A>>B>>C;
        v.emplace_back(A,B,C);
    }
    int U,V; cin>>U>>V;
    sort(v.begin(), v.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });
    int res=INF;
    while(1){
        if(Find(U)==Find(V)) break;
        Edge k=v.back(); v.pop_back();
        Union(k.u, k.v);
        res=k.w;
    }
    cout << res << '\n';
}