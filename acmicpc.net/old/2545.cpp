#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    vector<ll> v;
    while(T--){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        v.clear();
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end(), greater<ll>());
        if(v[0]-v[1]<=d){
            d-=v[0]-v[1];
            v[0]=v[1];
            if(v[0]-v[2]+v[1]-v[2]<=d){
                d-=v[0]-v[2]+v[1]-v[2];
                v[0]=v[2];
                v[1]=v[2];
                v[0]-=d/3;
                v[1]-=d/3;
                v[2]-=d/3;
                d=d%3;
                if(d>0){
                    v[0]-=1;
                    d-=1;
                }
                if(d>0){
                    v[1]-=1;
                    d-=1;
                }
            }
            else{
                v[0]-=d/2;
                v[1]-=d-d/2;
            }
        }
        else{
            v[0]-=d;
        }
        cout << v[0]*v[1]*v[2] << '\n';
    }
}