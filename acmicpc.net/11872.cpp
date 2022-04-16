#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    int N; cin>>N;
    ll res=0;
    for(int i=0; i<N; ++i){
        ll a; cin>>a;
        if(a==0) continue; 
        if((a-1)%4==2) res^=(a+1);
        else if((a-1)%4==3) res^=(a-1);
        else res^=a;
    }
    if(res==0) cout << "cubelover\n";
    else cout << "koosaga\n";
}