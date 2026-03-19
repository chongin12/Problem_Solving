#include <bits/stdc++.h>
using ll=long long;
using namespace std;
ll arr[16];
int main(){
    arr[0]=1;
    ll N, A, B, C; cin>>N>>A>>B>>C;
    for(ll i=1; i<=15; ++i){
        arr[i]=arr[i-1]*i;
    }
    cout << arr[N]/(arr[A]*arr[B]*arr[C]) << '\n';
}