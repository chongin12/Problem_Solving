#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    ll N, M; cin>>N>>M;
    if(N%M==0) cout << N/M << '\n';
    else {
        if(N/M!=0) cout << N/M << ' ';
        ll a=N%M, b=M;
        cout << a/gcd(a,b) << "/" << b/gcd(a,b) << '\n';
    }
}