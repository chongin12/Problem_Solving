#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 1000000;
int main(){
    ll N; cin>>N;
    ll temp = N/2;
    ll res=0;
    for(ll i=2; i<=temp; ++i){
        res=(res+(N/i-1)*i)%MOD;
    }
    cout << res << '\n';
}