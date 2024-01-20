#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
vector<pii> G[100001];
ll visible[100001];
ll dist[100001];
const ll INF = 2e18;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<=100000; ++i) 
        dist[i]=INF;
    ll N, M; cin>>N>>M;
    for(ll i=0; i<N; ++i){
        cin>>visible[i];
        if(i==N-1) visible[i]=0;
    }
    for(ll i=0; i<M; ++i){
        ll a, b, t; cin>>a>>b>>t;
        if(visible[a] || visible[b]) continue;
        G[a].push_back({b,t});
        G[b].push_back({a,t});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {거리, 노드}
    pq.push({0, 0});
    dist[0]=0;
    while(!pq.empty()){
        ll cur = pq.top().y;
        ll acc = pq.top().x;
        pq.pop();
        if(dist[cur]!=acc) continue;
        if(cur==N-1){
            cout << acc << '\n';
            return 0;
        }
        for(auto it:G[cur]){
            if(dist[cur]+it.y<dist[it.x]){
                dist[it.x]=dist[cur]+it.y;
                pq.push({dist[it.x], it.x});
            } 
        }
    }
    cout << "-1\n";
}