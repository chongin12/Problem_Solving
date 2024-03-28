#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N,M; cin>>N>>M;
    ll MN=N+M;
    string str1, str2; cin>>str1>>str2;
    ll k1=0,k2=0;
    vector<ll> v1,v2;
    for(ll i=0; i<MN; ++i){
        if(str1[i]=='1') v1.push_back(i);
        if(str2[i]=='1') v2.push_back(i);
    }
    for(ll i=0; i<v1.size(); ++i){
        ll a=abs(v1[i]-v2[i]);
        k1+=a/2;
        k2+=a/2;
        if(a%2){
            if(k1>k2) k2++;
            else k1++;
        }
    }
    cout << k1*k1+k2*k2 << '\n';
}