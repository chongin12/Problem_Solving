#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ll s,k; cin>>s>>k;
    vector<int> v;
    for(int i=0; i<k; ++i){
        v.push_back(s/k);
    }
    for(int i=0; i<s%k; ++i){
        v[i]++;
    }
    ll res=1;
    for(auto it:v){
        res*=it;
    }
    cout << res << '\n';
}