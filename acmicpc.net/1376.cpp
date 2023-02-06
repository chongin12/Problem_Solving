#include <bits/stdc++.h>
using namespace std;
namespace fio {
    const int BSIZE = 524288;
    char buffer[BSIZE];
    int p = BSIZE;
 
    inline char readChar() {
        if (p == BSIZE) {
            fread(buffer, 1, BSIZE, stdin);
            p = 0;
        }
        return buffer[p++];
    }
 
    int readInt() {
        char c = readChar();
        while ((c < '0' || c > '9') && c != '-') {
            c = readChar();
        }
        int ret = 0;
        bool neg = c == '-';
        if (neg) c = readChar();
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return neg ? -ret : ret;
    }
}
const int MN=100001;
struct Node {
    int cnt, l;
    Node():Node(0,-1){}
    Node(int cnt, int l):cnt(cnt),l(l){}
};
int visited[MN];
int checked[MN];
vector<int> G[MN]; // G는 인덱스 0부터 시작.
vector<Node> seg[MN]; // seg는 인덱스 1부터 시작.
Node Update(int segidx, int idx, int val, int n, int l, int r){ // val이 0이면 G[segidx][idx]번 노드가 visit된 것.
    if(r<idx || idx<l) return seg[segidx][n];
    if(l==r) return seg[segidx][n] = val ? Node(1,idx) : Node();
    int mid = (l+r)/2;
    Node left=Update(segidx, idx, val, n*2, l, mid), right=Update(segidx, idx, val, n*2+1, mid+1, r);
    int leftmost=-1;
    if(left.cnt!=0) leftmost=left.l;
    else if(right.cnt!=0) leftmost=right.l;
    return seg[segidx][n]=Node(left.cnt+right.cnt,leftmost);
}
Node Query(int segidx, int L, int R, int n, int l, int r){
    if(r<L || R<l) return Node();
    if(L<=l && r<=R) return seg[segidx][n];
    int mid = (l+r)/2;
    Node left=Query(segidx, L, R, n*2, l, mid), right=Query(segidx, L, R, n*2+1, mid+1, r);
    int leftmost=-1;
    if(left.cnt!=0) leftmost=left.l;
    else if(right.cnt!=0) leftmost=right.l;
    return Node(left.cnt+right.cnt,leftmost);
}
int FindMiddle(int segidx, int val, int L, int R, int n, int l, int r){
    // val : 앞에서 val번째 원소 구하기
    Node left = seg[segidx][n*2];
    Node right = seg[segidx][n*2+1];
    return 0;
}

void dfs(int x){
    if(visited[x]) return;
    visited[x]=1;
    cout << x << ' ';
    // 1. 주변 인접 노드들에 대해 Update 수행.
    if(checked[x]==0) {
        checked[x]=1;
        for(auto nxt:G[x]){
            Update(nxt,lower_bound(G[nxt].begin(), G[nxt].end(),x)-G[nxt].begin()+1,0,1,1,G[nxt].size());
        }
    }
    
    while(1){
        Node k=Query(x,1,G[x].size(),1,1,G[x].size());
        // cout << "x : " << x << ", cnt : " << k.cnt << ", l : " << k.l << '\n';
        if(k.cnt==0) return;
        else if(k.cnt%2==0 || k.cnt==1){
            int nxt=G[x][k.l-1];
            Update(x,k.l,0,1,1,G[x].size());
            dfs(nxt);
        }
        else{
            int targetN=k.cnt/2;
            // 1부터 mid까지의 구간에 targetN개가 있어야 함.
            int l=1, r=G[x].size()+1;
            while(l<r-1){
                int mid=(l+r)/2;
                Node temp = Query(x,1,mid,1,1,G[x].size());
                if(temp.cnt <= targetN) l=mid;
                else r=mid;
            }
            int nxtidx=Query(x,r,G[x].size(),1,1,G[x].size()).l;
            Update(x,nxtidx,0,1,1,G[x].size());
            dfs(G[x][nxtidx-1]);
        }
    }
}
vector<pair<int,int>> edges;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N=fio::readInt();
    int M=fio::readInt();
    // int N,M; cin>>N>>M;
    for(int i=0; i<M; ++i){
        int u=fio::readInt();
        int v=fio::readInt();
        // int u,v; cin>>u>>v;
        if(u==v) continue;
        if(u>v) swap(u,v);
        edges.push_back({u,v});
    }
    sort(edges.begin(), edges.end());
    for(int i=0; i<edges.size(); ++i){
        if(i>0 && edges[i]==edges[i-1]) continue;
        G[edges[i].first].push_back(edges[i].second);
        G[edges[i].second].push_back(edges[i].first);
    }
    for(int i=1; i<=N; ++i){
        seg[i] = vector<Node>(G[i].size()*4+1);
        for(int j=0; j<G[i].size(); ++j){
            Update(i,j+1,1,1,1,G[i].size());
        }
    }
    dfs(1);
}

/*
1 => 2 3 4
2 => 1 3 5
3 => 1 2 4
4 => 1 4
5 => 2
*/