#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v1,v2;
ll f(ll k){
    ll ret=0;
    for(int i=0; i<v1.size(); ++i){
        ret=max(abs(v1[i]-k)+v2[i],ret);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        v1.clear();
        v2.clear();
        int n; cin>>n;
        for(int i=0; i<n; ++i){
            ll a; cin>>a; v1.push_back(a*1e7);
        }
        for(int i=0; i<n; ++i){
            ll a; cin>>a; v2.push_back(a*1e7);
        }
        ll lo=0, hi=1e15+1; // 소수점 없애려고 1e7로
        while(lo<hi-1){
            ll mid=lo+hi>>1;
            if(f(mid)-f(mid-1)<=0){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        cout.precision(7);
        cout << fixed;
        cout << (long double)lo/10000000 << '\n';
    }
}