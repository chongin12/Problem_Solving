#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> G[6];
int main(){
    ll N; cin>>N;
    vector<ll> v(6);
    ll area1Max=-1;
    ll area1Total=0;
    ll area1Min=51;
    ll area2Min=101;
    ll area3Min=151;
    for(ll i=0; i<6; ++i){
        cin>>v[i];
        area1Total+=v[i];
        area1Min=min(area1Min, v[i]);
        area1Max=max(area1Max, v[i]);
        for(ll j=0; j<6; ++j){
            if(j==i) continue;
            if(i+j==5) continue;
            G[i].push_back(j);
        }
    }
    for(int i=0; i<6; ++i){
        for(auto it:G[i]){
            area2Min=min(area2Min, v[i]+v[it]);
        }
    }

    area3Min=min({area3Min, v[0]+v[1]+v[2], v[0]+v[1]+v[3], v[0]+v[2]+v[4], v[0]+v[3]+v[4]});
    area3Min=min({area3Min, v[5]+v[1]+v[2], v[5]+v[1]+v[3], v[5]+v[2]+v[4], v[5]+v[3]+v[4]});
    
    if(N==1){
        cout << area1Total-area1Max << '\n';
    }
    else{
        ll res=0;
        res+=((N-2)*(N-2)*5+(N-2)*4)*area1Min;
        res+=((N-2)*8+4)*area2Min;
        res+=4*area3Min;
        cout << res << '\n';
    }
}