#include <bits/stdc++.h>
using namespace std;
const int MN = 100001;
int par[MN];
int mainGroup=-1;
int res=0;
void init(){
    for(int i=0; i<MN; ++i){
        par[i]=i;
    }
}
int Find(int x){
    if(x==-1) return -1;
    if(par[x]==x) return x;
    return par[x]=Find(par[x]);
}
bool Union(int a, int b, int t){
    a=Find(a);
    b=Find(b);
    if(a==b) return false;
    par[a]=b;
    res=t;
    return true;
}
struct Node {
    int u, v, t;
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    int N, M; cin>>N>>M;
    vector<Node> arr;
    for(int i=0; i<M; ++i){
        int u, v, t; cin>>u>>v>>t;
        arr.push_back({u,v,t});
    }
    sort(arr.begin(), arr.end(), [](Node a, Node b){
        return a.t < b.t;
    });
    for(int i=1; i<=arr.size(); ++i){
        auto now = arr[i-1];
        if(now.t!=i) break;
        if(!Union(now.u, now.v, now.t)){
            break;
        }
    }
    cout << res+1 << '\n';
}