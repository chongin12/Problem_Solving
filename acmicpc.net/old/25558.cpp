#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll f(ll a, ll b, ll c, ll d){
    return abs(a-c)+abs(b-d);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    ll sx,sy,ex,ey; cin>>sx>>sy>>ex>>ey;
    ll MD=987654321987654321, Midx=0;
    for(ll idx=0; idx<N; ++idx){
        ll M; cin>>M;
        ll tx=sx,ty=sy;
        ll cnt=0;
        for(ll i=0; i<M; ++i){
            ll a,b; cin>>a>>b;
            cnt+=f(tx,ty,a,b);
            tx=a, ty=b;
        }
        cnt+=f(tx,ty,ex,ey);
        if(cnt<MD){
            MD=cnt;
            Midx=idx;
        }
    }
    cout << Midx+1 << '\n';
}