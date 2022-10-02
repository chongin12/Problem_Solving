#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll MN = 2e5+1;
const ll INF = 1e18;

struct edge {
    ll v, w;
    edge(ll v, ll w) : v(v), w(w) {}
};
ll p[MN];
ll Find(ll x){
    if(p[x]==x) return x;
    return p[x]=Find(p[x]);
}
void Union(ll a, ll b){
    ll A=Find(a);
    ll B=Find(b);
    p[A]=B;
}

vector<edge> G[MN];
ll dist[MN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N,M; cin>>N>>M;
    for(ll i=0; i<MN; ++i){
        p[i]=i;
    }
    vector<ll> minus; //음수 사이클이 포함된 정점들
    for(ll i=0; i<M; ++i){
        ll u,v,a,b; cin>>u>>v>>a>>b;
        if(a+b<0){
            minus.push_back(u);
            minus.push_back(v);
            Union(u,v);
        }
        else{
            G[u].push_back(edge(v,a+b));
            G[v].push_back(edge(u,a+b));
            Union(u,v);
        }
    }
    ll T; cin>>T;
    bool flag=true;
    for(auto it:minus){
        if(Find(1)==Find(it)){
            flag=false;
            break;
        }
    }
    if(!flag){
        vector<ll> res;
        for(ll i=2; i<=N; ++i){
            if(Find(1)==Find(i)){
                res.push_back(i);
            }
        }
        cout << res.size() << '\n';
        for(auto it:res){
            cout << it << ' ';
        }
        cout << '\n';
    }
    else{
        //dijkstra
        for(ll i=1; i<=N; ++i){
            dist[i]=INF;
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,1});
        dist[1]=0;
        while(!pq.empty()){
            P top = pq.top(); pq.pop();
            ll curDist = top.first;
            ll curNode = top.second;

            if(dist[curNode] < curDist) continue;
            for(edge nxtEdge: G[curNode]){
                ll nxtNode = nxtEdge.v;
                if(dist[nxtNode] > dist[curNode] + nxtEdge.w){
                    dist[nxtNode]=dist[curNode]+nxtEdge.w;
                    pq.push({dist[nxtNode], nxtNode});
                }
            }
        }
        vector<ll> res;
        for(ll i=2; i<=N; ++i){
            if(Find(1)==Find(i)){
                if(dist[i]<=T*2){
                    res.push_back(i);
                }
            }
        }
        cout << res.size() << '\n';
        for(auto it:res){
            cout << it << ' ';
        }
        cout << '\n';
    }
}