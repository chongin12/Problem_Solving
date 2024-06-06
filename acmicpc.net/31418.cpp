#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // 각 바이러스마다 갈 수 있는 최소 최대 x, y를 구하기
    ll W, H, K, T; cin>>W>>H>>K>>T;
    ll res=1;
    for(ll i=0; i<K; ++i){
        ll x, y; cin>>x>>y;
        ll minX=max(1LL,x-T);
        ll minY=max(1LL,y-T);
        ll maxX=min(W,x+T);
        ll maxY=min(H,y+T);
        res*=(maxX-minX+1);
        res%=MOD;
        res*=(maxY-minY+1);
        res%=MOD;
    }
    cout << res%MOD << '\n';
}