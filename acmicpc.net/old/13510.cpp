// HLD 를 이용한 풀이
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX_V = 100101;
ll seg[MAX_V*4];
ll Query(int L, int R, int n, int l, int r){
    if(L<=l && r<=R) return seg[n];
    if(R<l || r<L) return 0; 
    int mid=(l+r)/2;
    return max(Query(L, R, n*2, l, mid), Query(L, R, n*2+1, mid+1, r));
}
ll Update(int idx, ll val, int n, int l, int r){
    if(r<idx || idx<l) return seg[n];
    if(l==r) return seg[n]=val;
    int mid=(l+r)/2;
    return seg[n]=max(Update(idx, val, n*2, l, mid),Update(idx,val,n*2+1,mid+1,r));
}
ll SegQuery(int u, int v){
    return Query(u, v, 1, 1, MAX_V);
}
void SegUpdate(int idx, ll val){
    Update(idx, val, 1, 1, MAX_V);
}
/*
 * Sz[v] : v를 루트로 하는 서브 트리의 크기
 * Dep[v] : v의 깊이
 * Par[v] : v의 부모 정점
 * Top[v] : v가 속한 체인에서 맨 위에 있는 정점
 * In[v] : DFS에서 v에 들어가는 시간
 * Out[v] : DFS에서 v를 빠져나오는 시간
 * G[v] : v의 자식 정점
 */
int Sz[MAX_V], Dep[MAX_V], Par[MAX_V], Top[MAX_V], In[MAX_V], Out[MAX_V];
vector<int> G[MAX_V];

void DFS1(int v){
    Sz[v] = 1;
    for(auto &i : G[v]){
        if(Par[v]==i) continue;
        Dep[i] = Dep[v]+1; Par[i] = v;
        DFS1(i); Sz[v] += Sz[i];
        if(Sz[i] > Sz[G[v][0]]) swap(i, G[v][0]); // 가장 무거운 정점이 맨 앞으로
    }
}
void DFS2(int v) {
    static int cnt=0;
    In[v] = ++cnt;
    for(auto i:G[v]){
        if(Par[v]==i) continue;
        //간선 (v, i)가 light edge면 i가 새로운 체인의 top, heavy edge면 v와 같은 체인.
        Top[i] = i == G[v][0] ? Top[v] : i;
        DFS2(i);
    }
    Out[v] = cnt;
}
ll PathQuery(int u, int v){
    ll ret=0;
    for(; Top[u]!=Top[v]; u=Par[Top[u]]){
        if(Dep[Top[u]] < Dep[Top[v]]) swap(u,v);
        ret=max(ret,SegQuery(In[Top[u]], In[u]));
    }
    if(In[u] > In[v]) swap(u, v);
    ret=max(ret,SegQuery(In[u]+1, In[v]));
    return ret;
}
struct node {
    int u, v; ll w;
    node(int u, int v, ll w):u(u),v(v),w(w){}
};
vector<node> V;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N-1; ++i){
        int u,v; ll w; cin>>u>>v>>w;
        G[u].push_back(v);
        G[v].push_back(u);
        V.push_back(node(u,v,w));
    }
    DFS1(1);
    DFS2(1);
    for(auto it:V){
        if(it.u==Par[it.v]) SegUpdate(In[it.v], it.w);
        else SegUpdate(In[it.u], it.w);
    }
    int M; cin>>M;
    for(int i=0; i<M; ++i){
        ll q,a,b; cin>>q>>a>>b;
        if(q==1){
            node k=V[a-1];
            if(k.u==Par[k.v]) SegUpdate(In[k.v], b);
            else SegUpdate(In[k.u], b);
        }
        else{
            cout << PathQuery(a, b) << '\n';
        }
    }
}