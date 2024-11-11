#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n, m; cin>>n>>m;
    ll r=1e18;
    for(int i=0; i<m; ++i){
        ll u, d; cin>>u>>d;
        ll lo=0, hi=n+1;
        while(lo+1<hi){
            ll mid=(lo+hi)/2;
            if(u*mid-d*(n-mid)>0){
                hi=mid;
            }
            else{
                lo=mid;
            }
        }
        r=min(r,u*hi-d*(n-hi));
    }
    cout << r << '\n';
}