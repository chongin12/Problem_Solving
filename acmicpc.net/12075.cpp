#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll T; cin>>T;
    for(ll t=1; t<=T; ++t){
        ll K; cin>>K; K--;
        cout << "Case #" << t << ": ";
        while(K%4==3){
            K/=4;
        }
        if(K%4==0){
            cout << "0\n";
        }
        if(K%4==1){
            if((K/4)%2) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
        if(K%4==2){
            cout << "1\n";
        }
    }
}