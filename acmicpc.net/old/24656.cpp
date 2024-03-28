#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    ll res=0;
    for(int i=0; i<N; ++i){
        ll a,b; cin>>a>>b;
        if(b%2){
            if(a%2){
                res^=1;
            }
            else{
                res^=0;
            }
        }
        else{
            if(a%(b+1)==b){
                res^=2;
            }
            else if((a%(b+1))%2){
                res^=1;
            }
            else{
                res^=0;
            }
        }
    }
    if(res==0){
        cout << "Bob\n";
    }
    else{
        cout << "Alice\n";
    }
}