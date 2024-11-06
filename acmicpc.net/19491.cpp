#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll k,a,b; cin>>k>>a>>b;
    ll r=0;
    for(ll x=1; x<=1458; ++x){
        if(k*x<a) continue;
        if(k*x>b) break;
        ll t=x*k, cnt=0;
        while(t) cnt+=(t%10)*(t%10), t/=10;
        if(cnt==x) r++;
    }
    cout << r << '\n';
}