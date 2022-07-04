#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN = 10000000;
ll seg[MN*4+1];

ll Update(ll idx, ll n, ll l, ll r) {
    if(r<idx || idx<l) return seg[n];
    if(l==r) return ++seg[n];
    ll mid = (l+r)/2;
    return seg[n] = Update(idx, n*2, l, mid) + Update(idx, n*2+1, mid+1, r);
}

ll Query(ll L, ll R, ll n, ll l, ll r) {
    if (r<L || R<l) return 0;
    if(L<=l && r<=R) return seg[n];
    ll mid = (l+r)/2;
    return Query(L, R, n*2, l, mid) + Query(L, R, n*2+1, mid+1, r);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int Q; cin>>Q;
    set<ll> zero; // zero 판별할 때는 좌표압축 x
    vector<vector<ll> > queries;
    vector<ll> v;
    while(Q--){
        vector<ll> toPush;
        ll c; cin>>c; toPush.push_back(c);
        if(c==1){
            ll a,b; cin>>a>>b;
            toPush.push_back(a);
            toPush.push_back(b);
            if(a==0){
                queries.push_back(toPush);
                v.push_back(0);
                continue;
            }
            ll r=b/a;
            if(b%a!=0){
                if(a<0){
                    if(b>0){
                        r-=1;
                    }
                }
                else{
                    if(b<0){
                        r-=1;
                    }
                }
            }
            v.push_back(r);
        }
        else{
            ll a; cin>>a;
            v.push_back(-a);
            toPush.push_back(-a);
        }
        queries.push_back(toPush);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll N=v.size()+1;
    ll k=1;
    for(auto query:queries) {
        if(query[0]==1){
            ll a=query[1], b=query[2];
            if(a==0){
                if(b==0) k*=0;
                else if(b>0) k*=1;
                else k*=-1;
            }
            else{
                if(a>0) {
                    k*=1;
                }
                else {
                    k*=-1;
                }
                ll r=b/a;
                if(b%a!=0){
                    if(a<0){
                        if(b>0){
                            r-=1;
                        }
                    }
                    else{
                        if(b<0){
                            r-=1;
                        }
                    }
                }
                else{
                    zero.insert(r);
                }
                
                ll tar=lower_bound(v.begin(), v.end(), r)-v.begin()+1;
                Update(tar,1,1,N);
            }

        }
        else{
            ll c=query[1];
            if(zero.find(c)!=zero.end()){
                cout << "0\n";
            }
            else{
                ll zip=lower_bound(v.begin(), v.end(), c)-v.begin()+1;
                ll cnt=Query(1,zip-1,1,1,N);
                ll sg=1;
                if(cnt%2) sg=-1;
                if(k*sg==0) cout << "0\n";
                else if(k*sg<0) cout << "-\n";
                else cout << "+\n";
            }
        }
    }
}