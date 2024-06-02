#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int,int>;
vector<pii> G[5001];
int dist[5001];
const int INF = 987654321;
void init(){
    for(int i=0; i<5001; ++i){
        dist[i]=INF;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int V, E, P; cin>>V>>E>>P;
    for(int i=0; i<E; ++i){
        int a, b, c; cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // V번에서 P번과 1번까지의 최단경로를 구하기
    init();
    dist[V]=0;
    pq.push({0, V});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        // cout << "cur : " << cur.x << ", " << cur.y << '\n';
        if(dist[cur.y]!=cur.x) continue;
        for(auto it:G[cur.y]) {
            if(dist[it.x]>dist[cur.y]+it.y){
                dist[it.x]=dist[cur.y]+it.y;
                pq.push({dist[it.x], it.x});
            }
        }
    }

    int v2p=dist[P], v21=dist[1];

    // P번에서 1번까지의 최단경로를 구하기
    init();
    dist[P]=0;
    pq.push({0, P});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(dist[cur.y]!=cur.x) continue;
        for(auto it:G[cur.y]) {
            if(dist[it.x]>cur.x+it.y){
                dist[it.x]=cur.x+it.y;
                pq.push({dist[it.x], it.x});
            }
        }
    }

    int p21=dist[1];

    // cout << "v2p : " << v2p << ", v21 : " << v21 << ", p21 : " << p21 << '\n';

    if(v2p+p21==v21){
        cout << "SAVE HIM\n";
    }
    else {
        cout << "GOOD BYE\n";
    }
}