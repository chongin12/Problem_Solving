#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MN = 1000000 + 1;
ll arr[MN];
ll acc[MN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(ll i=1; i<MN; ++i){
        for(ll j=1; i*j<MN; ++j){
            arr[i*j]+=i;
        }
        acc[i]=acc[i-1]+arr[i];
    }
    ll T; cin>>T;

    while(T--){
        ll N; cin>>N;
        cout << acc[N] << '\n';
    }
}