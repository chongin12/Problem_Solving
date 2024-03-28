#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int main(){
    ll n; cin>>n;
    ll lo=0, hi=(ll)1<<32;
    while(lo<hi-1){
        // cout << "lo : " << lo << ", hi : " << hi << '\n';
        ll mid=(lo+hi)/2;
        // cout << "mid * mid : " << mid*mid << '\n';
        if(mid*mid>=n) hi=mid;
        else lo=mid;
    }
    if(n==0) cout << "0\n";
    else cout << hi << '\n';
}