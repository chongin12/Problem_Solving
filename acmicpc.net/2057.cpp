#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll cache[20];
int main(){
    ll N; cin>>N;
    if(N==0) {
        cout << "NO\n";
        return 0;
    }
    cache[0]=1;
    for(ll i=1; i<20; i+=1) cache[i]=cache[i-1]*i;
    for(int i=19; i>=0; --i){
        if(N>=cache[i]) N-=cache[i];
    }
    if(N){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }
}