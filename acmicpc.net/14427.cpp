#include <bits/stdc++.h>
using namespace std;
const int MN=100001;
int seg[MN*4+1];
int Update(int idx, int val, int n, int l, int r){
    // cout << "n : " << n << ", l : " << l << ", r : " << r << '\n';
    if(idx<l || r<idx) return seg[n];
    if(l==r) return seg[n]=val;
    int mid=(l+r)/2;
    return seg[n]=min(Update(idx, val, n*2, l, mid), Update(idx,val, n*2+1, mid+1, r));
}
int f(int n, int l, int r){
    if(l==r) return l;
    int mid=(l+r)/2;
    if(seg[n*2]<=seg[n*2+1]) return f(n*2, l, mid);
    else return f(n*2+1, mid+1, r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    fill(seg, seg+MN*2+1, 987654321);
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        Update(i, a, 1, 1, N);
    }
    int M; cin>>M;
    for(int i=0; i<M; ++i){
        int q; cin>>q;
        if(q==1){
            int a,b; cin>>a>>b;
            Update(a, b, 1, 1, N);
        }
        else{
            cout << f(1, 1, N) << '\n';
        }
    }
}