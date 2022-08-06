#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        cout << "Case #"<<t<<'\n';
        ll N,K; cin>>N>>K;
        vector<ll> v;
        for(int i=0; i<N; ++i){
            ll a; cin>>a;
            v.push_back(a);
        }
        ll l=0, r=v.size()-1;
        ll res=0;
        ll cnt=0;
        ll shift=0;
        while(l<=r){
            if(v[l]+shift>=K){
                l++;
                continue;
            }
            if(v[r]+shift>=K){
                r--;
                continue;
            }
            ll temp=min(K-v[l]-shift, K-v[r]-shift);
            res+=temp*(r-l+1);
            cnt+=temp;
            shift+=temp;
        }
        cout << cnt << " " << res << '\n';
    }
}