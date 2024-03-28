#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll P=524287, M=998244353;
vector<ll> H, B;
ll cnt=0;
ll hashValue = 0;
string str;
ll k=1;
vector<pair<int,char>> G[500011];
void dfs(int x){
    int n=H.size();
    if(n>str.size()){
        ll res = (H[n-1]-H[n-str.size()-1]*k)%M;
        res=(res+M)%M;
        if(res<0) res+=M;
        if(res==hashValue) cnt++;
    }
    for(auto nxt:G[x]){
        H.push_back((H.back()*P+nxt.second)%M);
        dfs(nxt.first);
        H.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N-1; ++i){
        int u, v; char ch; cin>>u>>v>>ch;
        G[u].push_back({v,ch});
    }
    cin>>str;
    for(int i=0; i<str.size(); ++i){
        hashValue = (hashValue*P+str[i])%M;
        k=k*P%M;
    }
    H.push_back(0);
    dfs(1);
    cout << cnt << '\n';
}