#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;
vector<ll> prime;
ll isErased[15001];
ll y[4]={1,3,7,9};
void f(ll x, ll step=1){
    if(step==N){
        cout << x << '\n';
        return;
    }
    for(ll i=0; i<4; ++i){
        ll temp=x*10+y[i];
        // temp가 소수인지 판별
        bool flag=true;
        for(ll j=0; j<prime.size() && prime[j]*prime[j]<=temp; ++j){
            if(temp%prime[j]==0){
                flag=false;
                break;
            }
        }
        if(flag) f(temp, step+1);
    }
}
int main(){
    cin>>N;
    for(ll i=2; i*i<15001; ++i){
        if(!isErased[i]){
            for(ll j=i*i; j<15001; j+=i){
                isErased[j]=1;
            }
        }
    }
    for(ll i=2; i<15001; ++i){
        if(!isErased[i]) prime.push_back(i);
    }
    f(2);
    f(3);
    f(5);
    f(7);
}