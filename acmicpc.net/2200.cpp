#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int N; cin>>N;
    ll a; cin>>a;
    ll res=1;
    for(int i=1; i<=N; ++i){
        cin>>a;
        if(a==0){
            res+=2;
            continue;
        }
        while(a>0) {
            res+=1;
            a/=10;
        }
        res+=3;
    }
    cout << res-1 << '\n';
}