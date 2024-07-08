#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int chk[200001];
vector<pii> G[200001];
void init(){
    memset(chk, 0, sizeof chk);
    for(int i=0; i<200001; ++i) G[i].clear();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        int M, N; cin>>M>>N;
        if(M+N==0) break;
        init();
        int sum = 0;
        for(int i=0; i<N; ++i){
            int x, y, z; cin>>x>>y>>z;
            G[x].push_back({y,z});
            G[y].push_back({x,z});
            sum+=z;
        }
        chk[1]=1;
        priority_queue<pii, vector<pii>, greater<pii> > pq; // {거리, 목적지 노드}
        for(auto it:G[1]) pq.push({it.second, it.first});
        int res=0;
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            if(chk[cur.second]) continue;
            chk[cur.second]=1;
            res+=cur.first;
            for(auto it:G[cur.second]) {
                if(chk[it.first]) continue;
                pq.push({it.second, it.first});
            }
        }
        cout << sum - res << '\n';
    }
}