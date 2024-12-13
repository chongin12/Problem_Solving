#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N; cin>>N;
    ll a=1, b=1, c=1, d=1;
    for(ll i=3; i<N; ++i){
        d=a+c;
        a=b;
        b=c;
        c=d;
    }
    cout << d << '\n';
}