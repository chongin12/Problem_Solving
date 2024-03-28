// HLD 를 이용한 풀이
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX_V = 200101;
ll seg[MAX_V*4];
ll Sum(int L, int R, int n, int l, int r){
    if(L<=l && r<=R) return seg[n];
    if(R<l || r<L) return 0; 
    int mid=(l+r)/2;
    return Sum(L, R, n*2, l, mid) + Sum(L, R, n*2+1, mid+1, r);
}
ll QueryLeftmost(int L, int R){
    // L~R 구간 중 가장 왼쪽에 있는 1의 인덱스 반환
    if(L==R && Sum(L, L, 1, 1, MAX_V)) return L;
    int mid=(L+R)/2;
    if(Sum(L, mid, 1, 1, MAX_V)) return QueryLeftmost(L, mid);
    else if(Sum(mid+1, R, 1, 1, MAX_V)) return QueryLeftmost(mid+1, R);
    else return -1;
}
ll QueryRightmost(int L, int R){
    // L~R 구간 중 가장 오른쪽에 있는 1의 인덱스 반환
    if(L==R && Sum(L, L, 1, 1, MAX_V)) return L;
    int mid=(L+R)/2;
    if(Sum(mid+1, R, 1, 1, MAX_V)) return QueryRightmost(mid+1, R);
    else if(Sum(L, mid, 1, 1, MAX_V)) return QueryRightmost(L, mid);
    else return -1;
}
ll Update(int idx, int n, int l, int r){
    if(r<idx || idx<l) return seg[n];
    if(l==r) return seg[n]= seg[n]==0 ? 1 : 0;
    int mid=(l+r)/2;
    return seg[n]=Update(idx, n*2, l, mid) + Update(idx,n*2+1,mid+1,r);
}
ll SegQuery(int u, int v){
    return Sum(u, v, 1, 1, MAX_V);
}
void SegUpdate(int idx){
    Update(idx, 1, 1, MAX_V);
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
int InvIn[MAX_V]; // InvIn[i] : In[k] 값이 i인 k 값이 들어있다.

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
    InvIn[cnt]=v;
    for(auto i:G[v]){
        if(Par[v]==i) continue;
        //간선 (v, i)가 light edge면 i가 새로운 체인의 top, heavy edge면 v와 같은 체인.
        Top[i] = i == G[v][0] ? Top[v] : i;
        DFS2(i);
    }
    Out[v] = cnt;
}
ll PathQuery(int u, int v){
    ll ret=-1;
    ll k;
    for(; Top[u]!=Top[v]; ){
        if(Dep[Top[u]] < Dep[Top[v]]) {
            // v가 더 깊을 때
            k=QueryLeftmost(In[Top[v]], In[v]);
            if(k!=-1) ret=k;
            v=Par[Top[v]];
        }
        else{
            // u가 더 깊을 때
            int k=QueryRightmost(In[Top[u]], In[u]);
            if(k!=-1) return k;
            u=Par[Top[u]];
        }
    }
    if(In[u] > In[v]){
        k=QueryRightmost(In[v], In[u]);
    } 
    else {
        k=QueryLeftmost(In[u], In[v]);
    }
    if(k!=-1) ret=k;
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=0; i<N-1; ++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS1(1);
    DFS2(1);
    int M; cin>>M;
    for(int i=0; i<M; ++i){
        int b,c; cin>>b>>c;
        if(b==1) {
            SegUpdate(In[c]);
        }
        else{
            int k=PathQuery(1,c);
            if(k==-1){
                cout << "-1\n";
                continue;
            }
            cout << InvIn[k] << '\n';
        }
    }
}