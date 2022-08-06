#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN=300001;
deque<ll> dq[MN+1];
ll v[MN+1];
ll seg[MN*4+1];
bool visited[MN+1];
ll Update(int idx, int n, int l, int r){
    if(r<idx || idx<l) return seg[n];
    if(l==r) return ++seg[n];
    int mid = (l+r)/2;
    return seg[n] = Update(idx, n*2, l, mid) + Update(idx, n*2+1, mid+1, r);
}
ll Query(ll L, ll R, int n, int l, int r) {
    if(r<L || R<l) return 0;
    if(L<=l && r<=R) return seg[n];
    int mid = (l+r)/2;
    return Query(L, R, n*2, l, mid) + Query(L, R, n*2+1, mid+1, r);
}
void init(){
    for(int i=0; i<MN+1; ++i){
        dq[i].clear();
        visited[i]=false;
        v[i]=0;
    }
    for(int i=0; i<MN*4+1; ++i){
        seg[i]=0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        init();
        cout << "Case #"<<t<<endl;
        ll N; cin>>N;
        for(ll i=1; i<=N; i+=1){
            ll a; cin>>a;
            dq[a].push_back(i);
            v[i]=a;
        }
        ll res=0;
        for(int i=1; i<=N; ++i){
            if(dq[v[i]].size()<2) continue;
            if(visited[i]) continue;
            ll a=dq[v[i]].front(), b=dq[v[i]].back();
            res+=b-a-Query(a,b,1,1,MN);
            visited[a]=true;
            visited[b]=true;
            Update(a,1,1,MN);
            Update(b,1,1,MN);
            dq[v[i]].pop_front();
            dq[v[i]].pop_back();
        }
        cout << res << endl;
    }
}