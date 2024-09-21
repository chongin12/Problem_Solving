#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        vector<ll> v;
        ll n; cin>>n;
        ll sum=0;
        for(ll i=0; i<n; ++i){
            ll a; cin>>a;
            sum+=a;
            v.push_back(a);
        }
        if(n<=2){
            cout << "-1\n";
            continue;
        }
        sort(v.begin(), v.end());
        ll res=v[n/2]*2*n-sum+1;
        if(res<0) res=0;
        cout << res << '\n';
    }
}