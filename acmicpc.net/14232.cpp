#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MN=1e6;
bool isErased[MN];
vector<ll> primes;
int main(){
    ll k; cin>>k;
    for(int i=2; i*i<MN; ++i){
        for(int j=i*i; j<MN; j+=i){
            isErased[j]=1;
        }
    }
    for(int i=2; i<MN; ++i){
        if(!isErased[i]) primes.push_back(i);
    }

    vector<ll> res;
    for(auto it:primes){
        if(it*it>k) break;
        while(k%it==0){
            k/=it;
            res.push_back(it);
        }
    }
    if(k!=1) res.push_back(k);
    cout << res.size() << '\n';
    for(auto it:res){
        cout << it << " ";
    }
    cout << '\n';
}