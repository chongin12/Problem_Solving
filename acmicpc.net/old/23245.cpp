#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
vector<pii> v;
const ll MN=1000003;
ll segL[MN*4+1];
ll segR[MN*4+1];
ll cntL[MN+10];
ll cntR[MN+10];
ll UpdateL(int idx, ll val, int n, int l, int r){
    if(idx<l || r<idx) return segL[n];
    if(l==r) return segL[n]=val;
    int mid=(l+r)/2;
    return segL[n]=UpdateL(idx, val, n*2, l, mid)+UpdateL(idx, val, n*2+1, mid+1, r);
}
ll UpdateR(int idx, ll val, int n, int l, int r){
    if (idx < l || r < idx) return segR[n];
    if (l == r) return segR[n] = val;
    int mid = (l + r) / 2;
    return segR[n] = UpdateR(idx, val, n * 2, l, mid) + UpdateR(idx, val, n * 2 + 1, mid + 1, r);
}
ll QueryL(int L, int R, int n, int l, int r){
    if(r<L || R<l) return 0;
    if(L<=l && r<=R) return segL[n];
    int mid=(l+r)/2;
    return QueryL(L,R,n*2,l,mid)+QueryL(L,R,n*2+1,mid+1,r);
}
ll QueryR(int L, int R, int n, int l, int r){
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) return segR[n];
    int mid = (l + r) / 2;
    return QueryR(L, R, n * 2, l, mid) + QueryR(L, R, n * 2 + 1, mid + 1, r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        ll a; cin>>a;
        a+=1;
        v.push_back({a,0});
    }
    for(int i=0; i<n; ++i){
        ll a; cin>>a;
        a+=1;
        v[i].second=a;
        cntR[a]++;
        UpdateR(a,cntR[a],1,1,MN);
    }
    
    sort(v.begin(), v.end());
    // for(int i=0; i<n; ++i){
    //     cout << v[i].first << ", " << v[i].second << '\n';
    // }
    ll res=0;
    for(int i=0; i<n; ++i){
        vector<ll> toUpdate;
        toUpdate.push_back(v[i].second);
        cntR[v[i].second]-=1;
        UpdateR(v[i].second,cntR[v[i].second],1,1,MN);
        while(i+1<n && v[i+1].first==v[i].first) {
            i+=1;
            toUpdate.push_back(v[i].second);
            cntR[v[i].second]--;
            UpdateR(v[i].second,cntR[v[i].second],1,1,MN);
        }
        
        for(ll it:toUpdate){
            ll tmpL = QueryL(0, it - 1, 1, 1, MN);
            ll tmpR = QueryR(it+1, MN, 1, 1, MN);
            // cout << "it : " << it << ", tmpL : "<<tmpL<<", tmpR : " << tmpR << '\n';
            res += tmpL * tmpR;
        }
        for(ll it:toUpdate){
            cntL[it]++;
            UpdateL(it,cntL[it],1,1,MN);
        }
    }
    cout << res << '\n';
}