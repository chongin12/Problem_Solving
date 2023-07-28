#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> po, ne;
ll DEFAULT = 0;
ll N, D;
void init() {
    po.clear();
    ne.clear();
    DEFAULT=0;
}
ll f(ll x){ // 오른쪽으로 x만큼 갈 수 있을 때
    ll cnt=DEFAULT;
    auto it = upper_bound(po.begin(), po.end(), x) - po.begin();
    cnt+=it;
    ll y = D - 2*x;
    if(y>0){
        it = upper_bound(ne.begin(), ne.end(), y) - ne.begin();
        cnt+=it;
    }
    return cnt;
}
ll ff(ll x){ // 왼쪽으로 x만큼 갈 수 있을 때
    ll cnt=DEFAULT;
    auto it = upper_bound(ne.begin(), ne.end(), x) - ne.begin();
    cnt+=it;
    ll y = D - 2*x;
    if(y>0){
        it = upper_bound(po.begin(), po.end(), y) - po.begin();
        cnt+=it;
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    for(ll t=1; t<=T; ++t){
        init();
        cout << "Case #"<<t<<"\n";
        cin>>N>>D;
        for(ll i=0; i<N; ++i){
            ll k; cin>>k;
            if(k==0) DEFAULT++;
            else if(k>0) po.push_back(k);
            else ne.push_back(-k);
        }
        sort(po.begin(), po.end());
        sort(ne.begin(), ne.end());
        ll res=max(f(0), ff(0));
        for(ll i=0; i<po.size(); ++i){
            if(po[i]>D) break;
            res=max(res,f(po[i]));
        }
        for(ll i=0; i<ne.size(); ++i){
            if(ne[i]>D) break;
            res=max(res,ff(ne[i]));
        }
        cout << res << '\n';
    }
}