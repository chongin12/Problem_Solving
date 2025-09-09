//https://seastar105.tistory.com/54
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 1e5;
const int MXM = 1e6;
ll psum[MXM+5], a[100005];
int start_num[MXM+5], end_num[MXM+5];
ll back_num[MXM+5];
vector<int> roots(MXM+5);
vector<int> v;
int N, M, Q;

struct Node {
    int l, r, val;
    Node() : val(0) {};
};

vector<Node> tree(40*MXM);

int node_cnt;

void init() {
    node_cnt = 2*M;
    for(int i=1;i<M;++i) {
        tree[i].l = i << 1;
        tree[i].r = i << 1 | 1;
    }
}

void update(int node, int s, int e, int idx, int val) {
    tree[node].val += val;
    if(s != e) {
        int mid = s+e >> 1;
        int n1 = tree[node].l, n2 = tree[node].r;
        if(idx <= mid) {
            tree[node].l = node_cnt;
            tree[node_cnt++] = tree[n1];
            update(tree[node].l, s, mid, idx, val);
        }
        else {
            tree[node].r = node_cnt;
            tree[node_cnt++] = tree[n2];
            update(tree[node].r, mid+1, e, idx, val);
        }
    }
}

int query(int node, int k) {
    int l = 1, r = M;
    while(l != r) {
        int mid = l+r >> 1;
        int lsz = tree[tree[node].l].val;
        if(lsz >= k) {
            node = tree[node].l;
            r = mid;
        }
        else {
            node = tree[node].r;
            l = mid + 1;
            k -= lsz;
        }
    }
    assert(l == r);
    return l;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N >> M >> Q;
    for(int i=1;i<=N;++i) cin >> a[i];
    memset(start_num, -1, sizeof(start_num));
    memset(end_num, -1, sizeof(end_num));
    for(int i=1;i<=N;++i) {
        if(start_num[a[i]] == -1) {
            start_num[a[i]] = i;
            v.push_back(a[i]);
        }
        end_num[a[i]] = i;
    }
    vector<bool> vis(MXM+5, true);
    vector<int> tmp(MXN+5, 0);
    int cnt = M;
    for(int i=N;i>0;--i) {
        tmp[i] = cnt;
        if(vis[a[i]]) {
            vis[a[i]] = false; --cnt;
        }
    }
    ll total_sum = 0;
    for(int i=1;i<=M;++i) {
        if(start_num[i] == -1) back_num[i] = M;
        else back_num[i] = tmp[start_num[i]];
        total_sum += back_num[i];
    }
    for(int i=1;i<=M;++i) psum[i] = psum[i-1] + back_num[i];
    vector<pair<int,int>> p;
    for(int i=1;i<=M;++i) p.emplace_back(i, end_num[i]);
    sort(p.begin(), p.end(), [] (pair<int,int> &a, pair<int,int> &b) { return a.second < b.second; });
    init();
    roots[0] = 1;
    int idx = 0;
    int cur_root = 1;
    for(int &i:v) {
        while(idx < p.size() && p[idx].second <= start_num[i]) {
            tree[node_cnt] = tree[cur_root];
            cur_root = node_cnt++;
            update(cur_root, 1, M, p[idx++].first, 1);
        }
        roots[i] = cur_root;
    }
    for(int i=0;i<Q;++i) {
        ll k; cin >> k;
        if(total_sum < k) cout << "-1 -1" << '\n';
        else {
            int idx = lower_bound(psum, psum+M+1, k) - psum - 1;
            k -= psum[idx]; ++idx;
            if(back_num[idx] == M) cout << idx << ' ' << k << '\n';
            else {
                cout << idx << ' ' << query(roots[idx], k) << '\n';
            }
        }
    }
    return 0;
}