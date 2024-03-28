#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a, d, x;
ll sum(ll k){ // k개의 항에 대한 등차수열의 합
    return (k*(2*a+(k-1)*d))/2;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int Q; cin>>Q;
    while(Q--){
        cin>>a>>d>>x;
        ll lo=0, hi=1000000;
        while(lo<hi-1){
            ll mid = (lo+hi)/2;
            if(sum(mid)<x) lo=mid;
            else hi=mid;
        }
        cout << hi << " " << a+d*(hi-1)-(sum(hi)-x) << '\n';
    }
}