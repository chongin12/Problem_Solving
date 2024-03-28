#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN=100001;
struct node {
    ll lm, rm, m, sum;
    node():node(0,0,0,0){}
    node(ll lm, ll rm, ll m, ll sum):lm(lm),rm(rm),m(m),sum(sum){}
} seg[MN*4+1];
node Update(int idx, ll val, int n, int l, int r){
    if(idx<l || r<idx) return seg[n];
    if(l==r) return seg[n]=node(val,val,val,val);
    int mid=(l+r)/2;
    node left = Update(idx, val, n*2, l, mid);
    node right = Update(idx, val, n*2+1, mid+1, r);
    return seg[n]=node(
        max(left.lm, left.sum+right.lm), 
        max(right.rm, right.sum+left.rm),
        max({left.m, right.m, left.rm+right.lm}),
        left.sum+right.sum
    );
}
vector<node> v;
void Query(int L, int R, int n, int l, int r){
    if(R<l || r<L) return;
    if(L<=l && r<=R) {
        v.push_back(seg[n]);
        return;
    }
    int mid((l+r)/2);
    Query(L, R, n*2, l, mid);
    Query(L, R, n*2+1, mid+1, r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    for(int i=1; i<=N; ++i){
        ll a; cin>>a;
        Update(i, a, 1,1,N);
    }
    int M; cin>>M;
    while(M--){
        int a,b; cin>>a>>b;
        v.clear();
        Query(a,b,1,1,N);
        ll ret=-1e18;
        for(int i=0; i<v.size(); ++i) ret=max(ret,v[i].m);
        for(int i=2; i<=v.size(); ++i){ // 개수
            for(int j=0; j<=v.size()-i; ++j){ // 시작위치
                ll temp=0;
                for(int k=j; k<j+i; ++k){ // j ~ j+i 범위 탐색
                    if(k==j) temp+=v[k].rm;
                    else if(k==j+i-1) temp+=v[k].lm;
                    else temp+=v[k].sum;
                }
                ret=max(ret,temp);
            }
        }
        cout << ret << '\n';
    }
}