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
    bool flag[4]={0,0,0,0}; // 동서남북
    for(int i=0; i<N; ++i){
        if(abs(x-v[i].first)<=abs(y-v[i].second)){
            if(y<v[i].second){
                flag[3]=true;
            }
            else{
                flag[2]=true;
            }
        }
        if(abs(x-v[i].first)>=abs(y-v[i].second)){
            if(x<v[i].first){
                flag[1]=true;
            }
            else{
                flag[0]=true;
            }
        }
    }
    if(flag[0] && flag[1] && flag[2] && flag[3]){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }
}