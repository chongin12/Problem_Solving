#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int INF = 987654321;
vector<pii> G[10001];
int dist[10001];
void init(){
    for(int i=0; i<10001; ++i){
        G[i].clear();
        dist[i]=INF;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int ret=0;
        int cnt=0;
        init();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int n, d, c; cin>>n>>d>>c;
        for(int i=0; i<d; ++i){
            int a, b, s; cin>>a>>b>>s;
            G[b].push_back({a,s});
        }
        pq.push({0, c});
        dist[c]=0;
        while(!pq.empty()){
            pii cur = pq.top(); pq.pop();// 거리, 노드
            if(cur.first != dist[cur.second]) continue;
            for(auto it:G[cur.second]){ // 노드, 거리
                if(dist[it.first] > it.second + cur.first) {
                    dist[it.first] = it.second + cur.first;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        for(int i=1; i<=n; ++i){
            if(dist[i]==INF) continue;
            cnt++;
            ret=max(ret, dist[i]);
        }
        cout << cnt << " " << ret << '\n';
    }
}