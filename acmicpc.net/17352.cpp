#include <bits/stdc++.h>
using namespace std;
int p[300001];
void init(){
    for(int i=0; i<300001; ++i){
        p[i]=i;
    }
}
int Find(int a){
    if(a==p[a]) return a;
    return p[a]=Find(p[a]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    p[a]=b;
}
int main(){
    init();
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N-2; ++i){
        int u, v; cin>>u>>v;
        Union(u, v);
    }
    int k=Find(p[1]);
    for(int i=2; i<=N; ++i){
        if(k!=Find(p[i])){
            cout << k << ' ' << Find(p[i]) << '\n';
            return 0;
        }
    }
}