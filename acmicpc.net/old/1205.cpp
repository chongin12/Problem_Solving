#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll N,k,P; cin>>N>>k>>P;
    vector<ll> v(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    if(N==P && v[0]>=k) {
        cout << "-1\n";
    }
    else{
        cout << N-(upper_bound(v.begin(), v.end(), k)-v.begin())+1 << '\n';
    }
}