#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,P,Q,X,Y;
unordered_map<ll,ll> m;
ll f(ll i){
    if(m[i]) return m[i];
    if(i<=0) return 1;
    return m[i]=f(i/P-X)+f(i/Q-Y);
}
int main(){
    cin>>N>>P>>Q>>X>>Y;
    cout << f(N) << '\n';
}