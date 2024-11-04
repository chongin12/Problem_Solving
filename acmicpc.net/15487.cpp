#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[1000001];
ll acc[2][1000001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=1; i<=N; ++i){
        cin>>arr[i];
        if(i==1) acc[0][i]=-arr[i];
        else acc[0][i]=max(acc[0][i-1],-arr[i]);
    }
    for(ll i=2; i<=N; ++i){
        if(i==2) acc[1][i]=acc[0][i-1]+arr[i];
        else acc[1][i]=max(acc[1][i-1],acc[0][i-1]+arr[i]);
    }
    for(ll i=3; i<=N; ++i){
        if(i==3) acc[0][i]=acc[1][i-1]-arr[i];
        else acc[0][i]=max(acc[0][i-1],acc[1][i-1]-arr[i]);
    }
    ll res=-1e18;
    for(ll i=4; i<=N; ++i){
        res=max(res,acc[0][i-1]+arr[i]);
    }
    cout << res << '\n';
}