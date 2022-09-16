#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<pii> v;
    for(int i=0; i<N; ++i){
        ll a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    ll x,y; cin>>x>>y;
    bool f[4]={0,0,0,0};
    for(int i=0; i<N; ++i){
        int A=abs(x-v[i].first), B=abs(y-v[i].second);
        if(A<=B)
            if(y<v[i].second) f[3]=true;
            else f[2]=true;

        if(A>=B)
            if(x<v[i].first) f[1]=true;
            else f[0]=true;
    }
    cout << (f[0]&&f[1]&&f[2]&&f[3]?"NO\n":"YES\n");
}