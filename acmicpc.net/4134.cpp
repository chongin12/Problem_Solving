#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MN=4e9;
int isErased[1000101];
vector<ll> primes;
int main(){
    int N; cin>>N;
    for(int i=2; i*i<1000101; ++i){
        for(int j=i*i; j<1000101; j+=i){
            isErased[j]=1;
        }
    }
    for(int i=2; i<1000101; ++i){
        if(!isErased[i]) primes.push_back(i);
    }
    while(N--){
        ll a; cin>>a;
        if(a<2) {
            cout << "2\n";
            continue;
        }
        while(1){
            bool flag=true;
            for(auto it:primes){
                if(it*it>a) break;
                if(a%it==0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout << a << '\n';
                break;
            }
            a++;
        }
    }
}