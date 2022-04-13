#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    int N; cin>>N;
    ll res=0;
    for(int i=0; i<N; ++i){
        ll a; cin>>a;
        if(a==0 || a==2) res^=0;
        else if(a%2==1){
            res^=(a+1)/2;
        }
        else{
            res^=a/2-1;
        }
    }
    if(res==0) cout << "cubelover\n";
    else cout << "koosaga\n";
}