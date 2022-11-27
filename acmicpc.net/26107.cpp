#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll psum[101010];
ll grp[101010];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    ll curgrp=0, r=0;
    for(int i=1; i<=n; ++i){
        ll a,b; cin>>a>>b;
        if(r<a){
            ++curgrp;
            psum[curgrp]=psum[curgrp-1]+a-r;
            r=b;
            grp[i]=curgrp;
        }
        else{
            r=max(r,b);
            grp[i]=curgrp;
        }
    }
    ll prv=1;
    ll res=0;
    for(int i=0; i<k; ++i){
        ll a; cin>>a;
        if(grp[prv]>grp[a]){
            res+=psum[grp[prv]]-psum[grp[a]];
        }
        else{
            res+=psum[grp[a]]-psum[grp[prv]];
        }
        prv=a;
    }
    cout << res << '\n';
}