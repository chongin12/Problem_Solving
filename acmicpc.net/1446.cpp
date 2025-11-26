#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> G[10001];
int res=987654321;
int N, D;
void f(int cur, int acc){
    if(cur==D){
        res=min(res,acc);
        return;
    }
    for(auto it:G[cur]){
        f(it.first, acc+it.second);
    }
}
int main(){
    cin>>N>>D;
    set<int> pool = {0, D};
    for(int i=0; i<N; ++i){
        int s, e, l; cin>>s>>e>>l;
        pool.insert(s);
        pool.insert(e);
        G[s].push_back({e,l});
    }
    int prev=-1;
    for(auto it:pool){
        // cout << it << " ";
        if(prev==-1) prev=it;
        else{
            G[prev].push_back({it, it-prev});
            prev=it;
        }
    }
    f(0, 0);
    cout << res << '\n';
}