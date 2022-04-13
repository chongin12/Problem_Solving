#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    int N, M; cin>>N>>M;
    ll res=0;
    for(int i=0; i<N; ++i){
        ll temp=0;
        for(int j=0; j<M; ++j){
            ll a; cin>>a;
            temp+=a;
        }
        res^=temp;
    }
    if(res!=0) cout << "august14\n";
    else cout << "ainta\n";
}