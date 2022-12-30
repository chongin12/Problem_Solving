#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        ll n; cin>>n;
        vector<ll> v;
        int odd=0, even=0;
        for(ll i=0; i<n; ++i){
            ll a; cin>>a; 
            v.push_back(a);
            if(a%2) odd++;
            else even++;
        }
        sort(v.begin(), v.end());
        bool pass=true;
        for(int i=1; i<n; ++i){
            if(v[i]==v[i-1]) pass=false;
        }
        if(min(odd, even)>=2) pass=false;
        for(ll k=2; k<n; ++k){
            vector<int> temp(k);
            bool flag=false;
            for(int i=0; i<n; ++i){
                temp[v[i]%k]++;
            }
            for(int i=0; i<k; ++i){
                if(temp[i]<=1) flag=true;
            }
            if(!flag) {
                pass=false;
                break;
            }
        }

        if(pass) cout << "YES\n";
        else cout << "NO\n";
    }
}