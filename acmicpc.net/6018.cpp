#include <bits/stdc++.h>
using namespace std;
int par[1001];
void init(){
    for(int i=0; i<1001; ++i){
        par[i]=i;
    }
}
int Find(int x){
    if(x==par[x]) return par[x];
    return par[x]=Find(par[x]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    par[a]=b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, Q; cin>>N>>M>>Q;
    init();
    for(int i=0; i<M; ++i){
        int a, b; cin>>a>>b;
        Union(a,b);
    }
    for(int i=0; i<Q; ++i){
        int a, b; cin>>a>>b;
        if(Find(a)==Find(b)){
            cout << "Y\n";
        }
        else{
            cout << "N\n";
        }
    }
}