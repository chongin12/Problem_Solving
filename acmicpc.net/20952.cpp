#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 1e9+7;
ll arr[7];
void init(){
    for(ll i=0; i<=6; ++i){
        arr[i]=-1;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    ll N, M; cin>>N>>M;
    vector<ll> va, vb;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; va.push_back(a);
    }
    ll acc=0;
    for(ll j=0; j<M; ++j){
        ll b; cin>>b; vb.push_back(b);
        acc+=b;
        if(arr[acc%7]==-1) arr[acc%7]=j;
    }
    // for(ll i=0; i<=6; ++i){
    //     cout << "arr["<<i<<"]="<<arr[i]<<'\n';
    // }
    ll lastErasedStep=-1;
    for(ll i=0; i<N; ++i){
        if(arr[(7-va[i]%7)%7]==-1) {
            lastErasedStep=M; // 끝까지 살아남는게 있음
        }
        else {
            lastErasedStep=max(lastErasedStep, arr[(7-va[i]%7)%7]);
        }
    }
    if(lastErasedStep==M){
        ll totalAcc=0;
        for(ll i=0; i<M; ++i){
            totalAcc+=vb[i];
        }
        vector<ll> res;
        for(ll i=0; i<N; ++i){
            if(arr[(7-va[i]%7)%7]==-1) {
                res.push_back((va[i]+totalAcc)%MOD);
            }
        }
        cout << res.size() << '\n';
        for(auto it:res){
            cout << it << " ";
        }
        cout << '\n';
    }
    else {
        vector<ll> res;
        for(ll i=0; i<N; ++i){
            if(arr[(7-va[i]%7)%7]==lastErasedStep) res.push_back(va[i]);
        }
        ll toAdd=0;
        ll X=res[0];
        for(ll i=0; i<M; ++i){
            if((X+toAdd+vb[i])%7==0) continue;
            toAdd+=vb[i];
        }
        cout << res.size() << '\n';
        for(auto it:res){
            cout << (it+toAdd)%MOD << ' ';
        }
        cout << '\n';
    }
}