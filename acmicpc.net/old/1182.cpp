#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> v;
ll res=0;
ll N, S;
void f(ll cur, ll w, bool flag){
    if(cur==N){
        if(w==S && flag){
            res++;
        }
        return;
    }
    f(cur+1, w+v[cur], true);
    f(cur+1, w, flag);
}
int main(){
    cin>>N>>S;
    v.resize(N);
    for(int i=0; i<N; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    f(0,0,false);
    cout << res << '\n';
}