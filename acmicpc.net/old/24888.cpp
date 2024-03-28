#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const ll MN = 200011;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
vector<pii> G[MN];
vector<ll> DAG[MN];
ll N,M;
ll isNote[MN];
ll D[MN];
ll In[MN];
ll dp[MN];
priority_queue<pii, vector<pii>, greater<pii> > pq; // {거리, 노드}
void dijkstra(){
    for(ll i=0; i<MN; ++i) D[i]=INF;
    D[1]=0;
    pq.push({0, 1});
    while(!pq.empty()){
        pii c = pq.top(); pq.pop();
        ll curDist = c.x;
        ll cur = c.y;
        if(D[cur]<curDist) continue;
        for(auto nxtEdge: G[cur]){
            int nxt=nxtEdge.x;
            if(D[nxt] > D[cur] + nxtEdge.y){
                D[nxt] = D[cur] + nxtEdge.y;
                if(dp[nxt]<dp[cur]+isNote[nxt]){
                    dp[nxt]=dp[cur]+isNote[nxt];
                }
                pq.push({D[nxt], nxt});
            }
            else if(D[nxt] == D[cur] + nxtEdge.y){
                if(dp[nxt]<dp[cur]+isNote[nxt]){
                    dp[nxt]=dp[cur]+isNote[nxt];
                }
            }
        }
    }
}
vector<ll> res;
bool flag=false;
void dfs(ll X, ll prev=-1){
    if(flag) return;
    if(X==1){
        cout << res.size()+1 << '\n';
        for(int i=res.size()-1; i>=0; --i){
            cout << res[i] << " ";
        }
        cout << N << '\n';
        flag=true;
        return;
    }
    for(auto it:G[X]){
        ll nxtNode=it.x;
        ll nxtW = it.y;
        if(nxtNode==prev) continue;
        if(D[nxtNode]+nxtW!=D[X]) continue;
        if(dp[nxtNode]+isNote[X]!=dp[X]) continue;
        res.push_back(nxtNode);
        dfs(nxtNode);
        if(flag) return;
        res.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>M;
    for(ll i=0; i<M; ++i){
        ll u,v,w; cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    ll goal=0;
    for(ll i=1; i<=N; ++i){
        cin>>isNote[i];
        goal+=isNote[i];
    }
    dp[1]=isNote[1];
    dijkstra();
    if(dp[N]==goal) dfs(N);
    else cout << "-1\n";
}