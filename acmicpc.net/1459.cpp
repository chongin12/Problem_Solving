#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    ll X, Y, W, S; cin>>X>>Y>>W>>S;
    if(S>=W*2){
        cout << (X+Y)*W << '\n';
    }
    else{
        ll a=max(X,Y);
        ll b=min(X,Y);
        ll c=a-b;
        ll res=b*S;
        if(S>W){
            res+=c*W;
        }
        else{
            if(c%2) res+=W+(c-1)*S;
            else res+=c*S;
        }
        
        cout << res << '\n';
    }
}