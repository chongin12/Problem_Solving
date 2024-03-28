#include <bits/stdc++.h>
using namespace std;
const int MN=100000;
vector<int> seg[MN*4+1];
vector<int> arr;
void build(int n, int l, int r){
    if(l==r) {
        seg[n].push_back(arr[l-1]);
        return;
    }
    int mid=(l+r)/2;
    build(n*2, l, mid);
    build(n*2+1, mid+1, r);
    seg[n].resize(seg[n*2].size()+seg[n*2+1].size());
    merge(seg[n*2].begin(), seg[n*2].end(), seg[n*2+1].begin(), seg[n*2+1].end(), seg[n].begin());
}
int Query(int L, int R, int k, int n, int l, int r){
    if(R<l || r<L) return 0;
    if(L<=l && r<=R) {
        int it=upper_bound(seg[n].begin(), seg[n].end(), k)-seg[n].begin();
        return r-l+1-it;
    }
    int mid=(l+r)/2;
    return Query(L, R, k, n*2, l, mid)+Query(L, R, k, n*2+1, mid+1, r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        int a; cin>>a; arr.push_back(a);
    }
    build(1,1,N);
    int query; cin>>query;
    int x=0;
    while(query--){
        int a,b,c; cin>>a>>b>>c;
        x=Query(a^x,b^x,c^x,1,1,N);
        cout << x << '\n';
    }
}