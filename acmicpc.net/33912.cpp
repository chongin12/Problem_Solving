#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll A[100001];
int main(){
    ll N, M; cin>>N>>M;
    for(ll i=1; i<=N; ++i){
        ll a; cin>>a;
        A[a]=i;
    }
    ll res=987654321;
    ll rt1=A[1];
    for(ll i=2; i<M; ++i){
        // cout << "A["<<i-1<<"]="<<A[i-1]<<'\n';
        // cout << "A["<<i<<"]="<<A[i]<<'\n';
        if(A[i-1]<A[i]){
            rt1=rt1+A[i]-A[i-1];
        }
        else{
            rt1=rt1+A[i]+N-A[i-1];
        }
        // cout << "rt1="<<rt1<<'\n';
    }
    ll rt2=A[N];
    for(ll i=N-1; i>=M; --i){
        // cout << "A["<<i+1<<"]="<<A[i+1]<<'\n';
        // cout << "A["<<i<<"]="<<A[i]<<'\n';
        if(A[i+1]<A[i]){
            rt2=rt2+A[i]-A[i+1];
        }
        else{
            rt2=rt2+A[i]+N-A[i+1];
        }
        // cout << "rt2="<<rt2<<'\n';
    }

    if(rt1<rt2){
        cout << "CW\n";
    } else if(rt1>rt2){
        cout << "CCW\n";
    } else {
        cout << "EQ\n";
    }
}