#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        cout << "Case #" << t << endl;
        ll res=0;
        ll N; cin>>N;
        vector<ll> v;
        for(int i=0; i<N; ++i){
            ll a; cin>>a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        ll gap=N/4;
        for(int i=0; i<N/4; ++i){
            ll a=v[i];
            ll b=v[i+gap];
            ll c=v[i+gap*2];
            ll d=v[i+gap*3];
            res+=b-a+c-b+d-c+d-a;
        }
        cout << res << endl;
    }
}