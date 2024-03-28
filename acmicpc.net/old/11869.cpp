#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    int M; cin>>M;
    ll res=0;
    for(int i=0; i<M; ++i){
        ll k; cin>>k;
        res^=k;
    }
    if(res==0) cout << "cubelover\n";
    else cout << "koosaga\n";
}