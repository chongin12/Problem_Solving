#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int N,M; cin>>N>>M;
        vector<ll> v1, v2;
        for(int i=0; i<N; ++i){
            ll a; cin>>a; v1.push_back(a);
        }
        for(int i=0; i<M; ++i){
            ll a; cin>>a; v2.push_back(a);
        }
        sort(v1.begin(), v1.end(), greater<ll>());
        sort(v2.begin(), v2.end(), greater<ll>());
        while(1){
            if(v1.size()==0){
                cout << "B\n";
                break;
            }
            if(v2.size()==0){
                cout << "S\n";
                break;
            }
            if(v1.back() < v2.back()) v1.pop_back();
            else v2.pop_back();
        }
    }
}