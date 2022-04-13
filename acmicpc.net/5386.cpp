#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        ll S, K; cin>>S>>K;
        if(K%2){
            if(S%2){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else{
            if(S%(K+1) == K){
                cout << K << '\n';
            }
            else if((S%(K+1))%2){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
    }
}