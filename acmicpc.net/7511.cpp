#include <bits/stdc++.h>
using namespace std;
const int MN=1000001;
int par[MN];
void init(){
    for(int i=0; i<MN; ++i){
        par[i]=i;
    }
}
int Find(int a){
    if(par[a]==a) return a;
    return par[a]=Find(par[a]);
}
void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    par[b]=a;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    int cnt=0;
    while(T--){
        ++cnt;
        if(cnt>1) cout << '\n';
        cout << "Scenario "<<cnt<<":\n";
        init();
        int n, k; cin>>n>>k;
        for(int i=0; i<k; ++i){
            int a, b; cin>>a>>b;
            Union(a, b);
        }
        int m; cin>>m;
        for(int i=0; i<m; ++i){
            int u, v; cin>>u>>v;
            cout << (Find(u)==Find(v)?1:0) << '\n';
        }
    }
}