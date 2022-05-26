#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<pair<ll,ll> > v;
    for(int i=0; i<N; ++i){
        ll a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    int TT; cin>>TT;
    for(int i=1; i<=TT; ++i){
        ll V,T; cin>>V>>T;
        ll res=1987654321;
        for(int k=1; k<(1<<N); ++k){
            ll cnt=0;
            ll cost=0;
            for(int l=0; l<=N; ++l){
                if(k&(1<<l)){
                    cnt+=v[l].first * T;
                    cost+=v[l].second;
                }
            }
            if(cnt>=V) res=min(res,cost);
        }
        if(res==1987654321){
            cout << "Case "<<i<<": IMPOSSIBLE\n";
        }
        else{
            cout << "Case "<<i<<": "<<res << '\n';
        }
    }
}