#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    int prv=0;
    int prvamount=0;
    int acc=0;
    for(int i=0; i<N; ++i){
        if(acc>=100){
            prv=0;
            acc=0;
            prvamount=0;
        }
        int a; cin>>a;
        if(prv==a){
            prvamount*=2;
            acc+=prvamount;
        }
        else{
            prvamount=2;
            acc+=prvamount;
            prv=a;
        }
    }
    if(acc>=100) acc=0;
    cout << acc << '\n';
}