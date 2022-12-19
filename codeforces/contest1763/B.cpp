#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node{
    ll h, p;
    node(ll h, ll p):h(h),p(p){}
    node():node(0,0){}
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    while(T--){
        ll n, k; cin>>n>>k;
        vector<node> v(n);
        for(ll i=0; i<n; ++i){
            ll h; cin>>h;
            v[i].h=h-k;
        }
        for(ll i=0; i<n; ++i){
            ll p; cin>>p;
            v[i].p=p;
        }
        ll damage=0;
        sort(v.begin(), v.end(), [](node a, node b){
            return a.p<b.p;
        });
        bool pass=true;
        for(ll i=0; i<n; ++i){
            if(v[i].h<=damage) continue;
            if(k==0) {
                pass=false;
                break;
            }
            k=max(0LL,k-v[i].p);
            damage+=k;
            --i;
        }
        if(pass) cout << "YES\n";
        else cout << "NO\n";
    }
}
/*pq에 모든 power를 넣는다.
damage를 누적.
pq에서 뺀 몬스터가 죽었으면, 다른걸 뺀다.
pq에서 뺀 몬스터가 안죽었으면, 해당 값을 뺀 거를 데미지에 누적시키고, pq에 다시 넣는다.*/