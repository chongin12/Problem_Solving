#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> prime;
const ll MN=5000001;
bool isErased[MN];
bool isPel(ll a){
    deque<ll> dq;
    while(a>0){
        dq.push_back(a%10);
        a/=10;
    }
    while(dq.size()>1){
        if(dq.front() != dq.back()) return false;
        dq.pop_front();
        dq.pop_back();
    }
    return true;
}
int main(){
    for(ll i=2; i<MN; ++i){
        if(isErased[i]) continue;
        prime.push_back(i);
        for(ll j=i*i; j<MN; j+=i){
            isErased[j]=true;
        }
    }
    ll N; cin>>N;
    ll a = lower_bound(prime.begin(), prime.end(), N) - prime.begin();
    for(ll i=a; i<prime.size(); ++i){
        if(isPel(prime[i])){
            cout << prime[i] << '\n';
            break;
        }
    }
}