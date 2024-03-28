#include <bits/stdc++.h>
using namespace std;
struct MaxFlow {
    /*
     * edge_t : 간선의 정보
     * v : 목적지
     * c : 잔여 용량
     * r : reverse edge가 있는 위치(인덱스)
     */
    struct edge_t { int v, c, r; };
    vector<vector<edge_t>> G;

    /*
     * dst : 해당 정점까지의 거리(초기값 -1)
     * prv : (증가 경로에서) 이전 정점
     * idx : (증가 경로에서) 현재 정점
     */
    vector<int> dst, prv, idx;
    MaxFlow(int n):G(n),dst(n),prv(n),idx(n){}

    /*
     * addEdge : 간선 추가(무방향 그래프일 때)
     * s : 출발점
     * e : 도착점
     * c1 : 해당 간선의 용량
     * c2 : 해당 간선의 역방향 용량 (default 0)
     */
    void addEdge(int s, int e, int c1, int c2=0){
        G[s].push_back({e, c1, (int)G[e].size()});
        G[e].push_back({s, c2, (int)G[s].size()-1}); // reverse edge
    }

    /*
     * augment : s->t 증가경로가 있는지?
     * 리턴값은 경로가 없으면 0, 있으면 그 때 flow
     * 애드몬드-카프 알고리즘
     */
    int augment(int s, int t){
        fill(dst.begin(), dst.end(), -1);
        queue<int> q; q.push(s); dst[s] = 0;
        while(!q.empty()){
            int cur=q.front(); q.pop();
            for(int i=0; i<G[cur].size(); ++i){
                const auto &nxt = G[cur][i];
                if(nxt.c>0 && dst[nxt.v]==-1){
                    q.push(nxt.v);
                    dst[nxt.v]=dst[cur]+1;
                    prv[nxt.v]=cur;
                    idx[nxt.v]=i;
                }
            }
        }
        if(dst[t]==-1) return 0;
        int flow=1e9;
        for(int i=t; i!=s; i=prv[i]){
            const auto &e = G[prv[i]][idx[i]];
            flow = min(flow, e.c);
        }
        for(int i=t; i!=s; i=prv[i]){
            auto &e = G[prv[i]][idx[i]];
            e.c-=flow; G[e.v][e.r].c+=flow;
        }
        return flow;
    }

    /*
     * run : max flow 구하기
     */
    int run(int s, int t){
        int flow = 0, path = 0;
        while((path = augment(s, t)) != 0) flow+=path;
        return flow;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    MaxFlow MF(501);
    for(int i=0; i<m; ++i){
        int a,b,c; cin>>a>>b>>c;
        MF.addEdge(a,b,c,c);
    }
    int s, t; cin>>s>>t;
    cout << MF.run(s,t) << '\n';
}