#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long int;
ll toFind[]={2,7,61};
ll power(ll a, ll k, ll mod){
    ll res=1;
    a%=mod;
    while(k){
        if(k%2){
            res=(res*a)%mod;
        }
        k/=2;
        a=(a*a)%mod;
    }
    return res;
}
bool miller(ll a, ll N){ // N이 소수이면 true
    if(a%N==0) return true;
    ll k=N-1;
    while(1){
        ll x=power(a, k, N);
        if(x==N-1) return true;
        if(k%2==1) {
            return (x==1 || x==N-1);
        }
        k/=2;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    ll res=N;
    for(int i=0; i<N; ++i){
        ll a; cin>>a;
        for(int j=0; j<3; ++j){
            if(!miller(toFind[j], a*2+1)) {
                res-=1;
                break;
            }
        }
    }
    cout << res << '\n';
}