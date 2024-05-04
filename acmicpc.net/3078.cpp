#include <bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll, vector<ll> > m; // {길이, [성적들]}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N, K; cin>>N>>K;
    for(ll i=0; i<N; ++i){
        string str; cin>>str;
        m[str.size()].push_back(i);
    }
    ll cnt=0;
    for(auto it=m.begin(); it!=m.end(); ++it){
        auto arr = it->second;
        if(arr.size()<=1) continue;
        ll l=-1, r=0;
        while(++l<arr.size()){
            // r을 최대한으로 늘린다.
            //r-l을 정답 카운트에 늘린다.
            while(++r<arr.size() && arr[r]-arr[l]<=K) ;
            --r;
            cnt+=r-l;
        }
    }
    cout << cnt << '\n';
}