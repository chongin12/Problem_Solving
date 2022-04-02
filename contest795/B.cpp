#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const ll MOD=1000000007;
int N, Q;
ll arr[1001];
vector<int> G[1001];
vector<ll> res;
int Visit[1001];
void init(){
    res.clear();
    for(int i=0; i<1001; ++i){
        Visit[i]=0;
    }
}
void f(){
    ll t=arr[res[0]];
    for(int i=1; i<res.size(); ++i){
        ll jari=10;
        t=t*10;
        t%=MOD;
        while(arr[res[i]]/jari!=0) {
            jari*=10;
            t=t*10;
            t%=MOD;
        }
        t=t+arr[res[i]];
        t%=MOD;
    }
    cout << t << '\n';
}
void dfs(int x, int toFind){
    res.push_back(x);
    if(x==toFind) {
        f();
        return;
    }
    Visit[x]=1;
    for(auto nxt:G[x]){
        if(!Visit[nxt]){
            dfs(nxt, toFind);
        }
    }
    res.pop_back();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>Q;
    for(int i=1; i<=N; ++i){
        cin>>arr[i];
    }
    for(int i=0; i<N-1; ++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    while(Q--){
        int x,y; cin>>x>>y;
        init();
        dfs(x,y);
    }
    
}