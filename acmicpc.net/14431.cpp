#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int isErased[1000001];
struct Node {
    int x, y, num;
};
vector<pii> G[5000];
const int INF = 987654321;
int dist[5000];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    isErased[0]=1;
    isErased[1]=1;
    for(int i=2; i*i<=1000000; ++i){
        for(int j=i*i; j<=1000000; j+=i){
            isErased[j]=1;
        }
    }

    int X1,Y1,X2,Y2; cin>>X1>>Y1>>X2>>Y2;
    int N; cin>>N;
    vector<Node> v;
    for(int i=0; i<N; ++i){
        int a, b; cin>>a>>b;
        v.push_back({a,b,i});
    }
    v.push_back({X1,Y1,N});
    v.push_back({X2,Y2,N+1});
    for(int i=0; i<v.size(); ++i){
        for(int j=i+1; j<v.size(); ++j){
            int dist=floor(sqrt((double)(v[i].x-v[j].x)*(v[i].x-v[j].x)+(v[i].y-v[j].y)*(v[i].y-v[j].y)));
            // cout << "dist between "<<v[i].x<<", "<<v[i].y<<" / "<<v[j].x<<", "<<v[j].y<<"="<<dist<<'\n';
            if(isErased[dist]==0){
                G[i].push_back({j,dist});
                G[j].push_back({i,dist});
            }
        }
    }
    pq.push({0,N});
    for(int i=0; i<N+2; ++i) dist[i]=INF;
    dist[N]=0;
    // for(int i=0; i<N+2; ++i){
    //     cout << i << " : ";
    //     for(auto it:G[i]){
    //         cout << "("<<it.first<<", "<<it.second << ") ";
    //     }
    //     cout << '\n';
    // }
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int curDist=cur.first;
        int curNode=cur.second;
        if(dist[curNode]!= curDist) continue;

        for(auto it:G[curNode]){
            if(curDist+it.second<dist[it.first]){
                dist[it.first]=curDist+it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    if(dist[N+1]==INF) cout << "-1\n";
    else cout << dist[N+1] << '\n';
}