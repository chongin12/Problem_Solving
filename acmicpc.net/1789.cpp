#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    ll S; cin>>S;
    ll cnt=0;
    for(ll i=1;;++i){
        if(S-i<=i) break;
        S-=i;
        cnt++;
    }
    cout << cnt+1 << '\n';
}