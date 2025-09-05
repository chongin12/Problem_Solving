#include <bits/stdc++.h>
using namespace std;
struct Node {
    int l, r, val;
    Node():Node(0,0,0) {}
    Node(int l, int r, int val):l(l),r(r),val(val){}
};
int root[100002];
vector<Node> nodes;

void init(int nidx, int s, int e){
    if(s==e) return;
    int mid = (s+e)/2;
    nodes.push_back({});
    nodes[nidx].l = nodes.size() - 1;
    init(nodes[nidx].l, s, mid);

    nodes.push_back({});
    nodes[nidx].r = nodes.size() - 1;
    init(nodes[nidx].r, mid+1, e);
}
void Update(int idx, int delta, int nidx, int s, int e){
    if(s==e){
        return;
    }
    int mid = (s+e)/2;
    if(idx<=mid){
        int lidx = nodes[nidx].l;
        nodes.push_back({nodes[lidx].l, nodes[lidx].r, nodes[lidx].val+delta});
        nodes[nidx].l = nodes.size()-1;
        Update(idx, delta, nodes[nidx].l, s, mid);
    }
    else {
        int ridx = nodes[nidx].r;
        nodes.push_back({nodes[ridx].l, nodes[ridx].r, nodes[ridx].val+delta});
        nodes[nidx].r = nodes.size()-1;
        Update(idx, delta, nodes[nidx].r, mid+1, e);
    }
}
int Query(int l, int r, int nidx, int s, int e){
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return nodes[nidx].val;
    int mid = (s+e)/2;
    return Query(l, r, nodes[nidx].l, s, mid) + Query(l, r, nodes[nidx].r, mid+1, e);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        nodes.clear();
        nodes.push_back({});
        nodes.push_back({});
        memset(root, 0, sizeof root);
        root[0]=1;
        init(1, 1, 100001);
        int N, M; cin>>N>>M;
        vector<int> yidx[100002];
        for(int i=0; i<N; ++i){
            int x, y; cin>>x>>y;
            x++, y++;
            yidx[x].push_back(y);
        }
        for(int i=1; i<=100001; ++i){
            if(root[i]==0){
                nodes.push_back({nodes[root[i-1]].l, nodes[root[i-1]].r, nodes[root[i-1]].val});
                root[i]=nodes.size()-1;
            }
            for(auto it:yidx[i]){
                nodes[root[i]].val += 1;
                Update(it, 1, root[i], 1, 100001);
            }
        }

        int res=0;
        for(int i=0; i<M; ++i){
            int l, r, b, t; cin>>l>>r>>b>>t;
            l++, r++, b++, t++;

            res += Query(b, t, root[r], 1, 100001) - Query(b, t, root[l-1], 1, 100001);
        }
        cout << res << '\n';
    }
}