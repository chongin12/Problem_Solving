#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N; cin>>N;
    ll k=1, res=0;
    while(N>0){
        if(N%2) res+=k;
        N/=2;
        k*=3;
    }
    cout << res << '\n';
}