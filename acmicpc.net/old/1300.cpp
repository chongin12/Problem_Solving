#include <iostream>
#include <algorithm>
#define MAX 1e9
using namespace std;
using ll=long long int;
ll N;
ll f(ll x) { // x가 몇번째 수인지 리턴
    ll cnt=0;
    for(ll i=1; i<=N; i+=1){
        if(x/i==0) break;
        cnt+=min(x/i,N);
    }
    return cnt;
}
int main(){
    cin >> N;
    ll k; cin >> k;
    ll l=1, r=MAX+1, mid;
    while(l+1<=r){
        mid=(l+r)/2;
        ll temp=f(mid);
        if(temp>=k){
            r=mid;
        }
        else {
            l=mid+1;
        }
    }
    cout << l << '\n';
}