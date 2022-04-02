#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<int> G[100001];
ll val[100001];
ll res=0;
void init(){
    for(int i=0; i<100001; ++i){
        G[i].clear();
        val[i]=0;
        res=0;
    }
}
ll dfs(int x){
    if(G[x].size()){
        ll r=dfs(G[x][0]);
        for(int i=1; i<G[x].size(); ++i){
            ll temp=dfs(G[x][i]);
            if(r>temp) {
                res+=r;
                r=temp;
            }
            else {
                res+=temp;
            }
        }
        return max(r,val[x]);
    }
    return val[x];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    int cnt=0;
    while(T--){
        init();
        cout << "Case #"<<++cnt<<": ";
        int N; cin>>N;
        for(int i=1; i<=N; ++i){
            ll a; cin>>a; val[i]=a;
        }
        for(int i=1; i<=N; ++i){
            int a; cin>>a; G[a].push_back(i);
        }
        res+=dfs(0);
        cout << res << '\n';
    }
}