#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    #define int ll
    int N,M; cin>>N>>M;
    vector<int> v;
    for(int i=0; i<N; ++i){
        int a;cin>>a;
        v.push_back(a);
    }
    int res=0;
    int acc=0;
    for(int i=0; i<M; ++i){
        acc+=v[i];
    }
    res=acc;
    for(int i=0; i<N-M; ++i){
        acc+=v[i+M];
        acc-=v[i];
        res=max(res,acc);
    }
    cout << res << '\n';
}