#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using piii=pair<ll, pii>;
const ll INF = 1e18;
vector<pii> G[10001];
ll dist[10001][21];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, M, K; cin>>N>>M>>K;
    for(ll i=0; i<M; ++i){
        ll u,v,w; cin>>u>>v>>w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(ll i=0; i<10001; ++i){
        for(ll j=0; j<21; ++j){
            dist[i][j]=INF;
        }
    }
    priority_queue<piii, vector<piii>, greater<piii>> pq; // {dist, 그 때의 j값(포장 횟수), 목적지 노드}
    pq.push({0,{0,1}});
    dist[1][0]=0;
    while(!pq.empty()){
        piii cur = pq.top(); pq.pop();
        ll curNode = cur.second.second;
        ll curDist = cur.first;
        ll curj = cur.second.first;
        if(dist[curNode][curj] < curDist) continue;
        for(auto it:G[curNode]){
            if(dist[it.x][curj] > dist[curNode][curj] + it.y){
                dist[it.x][curj] = dist[curNode][curj] + it.y;
                pq.push({dist[it.x][curj],{curj, it.x}});
            }
            if(curj < K && dist[it.x][curj+1] > dist[curNode][curj]){
                dist[it.x][curj+1] = dist[curNode][curj];
                pq.push({dist[it.x][curj+1],{curj+1, it.x}});
            }
        }
    }
    ll res=INF;
    for(ll i=0; i<=K; ++i){
        res=min(res,dist[N][i]);
    }
    cout << res << '\n';
}