#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[200001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        cin>>arr[i];
    }
    ll Q; cin>>Q;
    while(Q--){
        ll what; cin>>what;
        if(what==1){
            ll c, x; cin>>c>>x;
            ll orix=x;
            for(ll i=c-1; i>=0; --i){
                if(arr[i]<=x){
                    x-=arr[i];
                    arr[i]*=2;
                }
                else {
                    arr[i]+=x;
                    break;
                }
            }
            x=orix;
            for(ll i=c; i<N; ++i){
                if(arr[i]<=x){
                    x-=arr[i];
                    arr[i]*=2;
                }
                else {
                    arr[i]+=x;
                    break;
                }
            }
        }
        else {
            ll c; cin>>c;
            cout << arr[c-1] << '\n';
        }
    }
}