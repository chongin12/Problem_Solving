#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<ll> v;
    for(int i=0; i<N; ++i){
        ll a; cin>>a;
        v.push_back(a);
    }
    int flag=true;
    for(int i=2; i<N; ++i){
        if(v[i]-v[i-1] != v[i-1]-v[i-2]){
            flag=false;
            break;
        }
    }
    if(flag){
        cout << "YES\n";
        for(auto it:v){
            cout << it*2 << ' ';
        }
        cout << '\n';
        for(auto it:v){
            cout << -it << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "NO\n";
    }
}