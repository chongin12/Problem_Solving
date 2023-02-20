#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N, K; cin>>N>>K;
    if(N<=K){
        cout << "0\n";
        return 0;
    }
    vector<ll> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    vector<ll> v2;
    ll sum=0;
    for(int i=1; i<N; ++i){
        sum+=v[i]-v[i-1];
        v2.push_back(v[i]-v[i-1]);
    }
    sort(v2.begin(), v2.end());
    for(int i=0; i<K-1; ++i){
        sum-=v2[v2.size()-1-i];
    }
    cout << sum << '\n';
}