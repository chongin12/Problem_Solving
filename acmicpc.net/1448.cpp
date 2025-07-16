#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    for(ll i=0; i<N; ++i){
        ll a; cin>>a; v.push_back(a);
    }
    sort(v.begin(), v.end());
    while(v.size()>=3){
        auto a=v[v.size()-1], b=v[v.size()-2], c=v[v.size()-3];
        if(a<b+c){
            cout << a+b+c << '\n';
            return 0;
        }
        v.pop_back();
    }
    cout << "-1\n";
}