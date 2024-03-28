#include <bits/stdc++.h>
using namespace std;
using ll=unsigned int;
const int MN=500100;
const int MAX_V = 500100;
ll seg[MN*4+1];
ll lazy[2][MN*4+1];
ll Update(int idx, ll val, int n, int l, int r){
    if(idx<l || r<idx) return seg[n];
    if(l==r) return seg[n]=val;
    int mid=(l+r)/2;
    return seg[n]=Update(idx, val, n*2, l, mid)+Update(idx,val,n*2+1,mid+1,r);
}
void UpdateLazy(int n, int l, int r){
    ll &mul=lazy[0][n];
    ll &sum=lazy[1][n];
    if(mul==1 && sum==0) return;
    if(l!=r){
        for(int i=n*2; i<=n*2+1; ++i){
            ll childMul = lazy[0][i], childSum = lazy[1][i];
            lazy[0][i] = childMul * mul;
            lazy[1][i] = childSum * mul + sum;
        }
    }
    seg[n]=mul*seg[n]+(r-l+1)*sum;
    mul=1, sum=0;
}
void UpdateRange(int L, int R, ll mul, ll sum, int n, int l, int r){
    UpdateLazy(n,l,r);
    if(R<l || r<L) return;

    if(L<=l && r<=R){
        lazy[0][n] *= mul;
        lazy[1][n] *= mul;
        lazy[1][n] += sum;
        UpdateLazy(n, l, r);
        return;
    }
    int mid=(l+r)/2;
    UpdateRange(L, R, mul, sum, n*2, l, mid);
    UpdateRange(L, R, mul, sum, n*2+1, mid+1, r);
    seg[n]=seg[n*2]+seg[n*2+1];
}
ll QueryLazy(int L, int R, int n, int l, int r){
    UpdateLazy(n,l,r);
    if(r<L || R<l) return 0;
    if(L<=l && r<=R) return seg[n];
    int mid=(l+r)/2;
    return QueryLazy(L,R,n*2,l,mid)+QueryLazy(L,R,n*2+1,mid+1,r);
}
ll SegQuery(int u, int v){
    return QueryLazy(u, v, 1, 1, MAX_V);
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
        ret+=SegQuery(In[Top[u]], In[u]);
    }
    if(In[u] > In[v]) swap(u, v);
    ret+=SegQuery(In[u], In[v]);
    return ret;
}
void PathUpdate(int u, int v, ll mul, ll sum){
    for(; Top[u]!=Top[v]; u=Par[Top[u]]){
        if(Dep[Top[u]] < Dep[Top[v]]) swap(u,v);
        UpdateRange(In[Top[u]], In[u], mul, sum, 1, 1, MN);
    }
    if(In[u] > In[v]) swap(u,v);
    UpdateRange(In[u], In[v], mul, sum, 1, 1, MN);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N,Q; cin>>N>>Q;
    for(int i=0; i<MN*4+1; ++i) lazy[0][i]=1, lazy[1][i]=0;
    for(int i=0; i<N-1; ++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS1(1);
    DFS2(1);
    //for(int i=1; i<=N; ++i){
    //    cout << "In["<<i<<"]="<<In[i]<<", Out["<<i<<"]="<<Out[i]<<'\n';
    //}
    for(int i=0; i<Q; ++i){
        int q; cin>>q;
        ll X,Y,V;
        if(q==5){
            cin>>X;
        }
        else if(q==1 || q==3){
            cin>>X>>V;
        }
        else if(q==2 || q==4){
            cin>>X>>Y>>V;
        }
        else{
            cin>>X>>Y;
        }
        if(q==1){
            UpdateRange(In[X], Out[X], 1, V, 1, 1, MN);
        }
        else if(q==2){
            PathUpdate(X, Y, 1, V);
        }
        else if(q==3){
            UpdateRange(In[X], Out[X], V, 0, 1, 1, MN);
        }
        else if(q==4){
            PathUpdate(X, Y, V, 0);
        }
        else if(q==5){
            cout << SegQuery(In[X], Out[X]) << '\n';
        }
        else{
            cout << PathQuery(X, Y) << '\n';
        }
        //for(int j=1; j<=N; ++j){
        //    cout << "금고 "<<j<<" : "<<SegQuery(In[j], In[j]) << '\n';
        //}
    }
}