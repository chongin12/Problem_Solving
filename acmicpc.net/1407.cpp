#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll f(ll X){ // X까지 f(1) 부터 f(X)까지의 총 합
    ll ret=0;
    ll cnt=1; // 2^(cnt-1)
    for(ll i=1; i<=X; i<<=1,cnt++) {
        // cout << "\ni : " << i << '\n';
        ll end = X|i;
        // cout << "end : " << end << '\n';
        if(end>X){
            end-=(i<<1);
        }
        // cout << "end : " << end << '\n';
        // cout << "end>>cnt + 1 : " << (end>>cnt)+1 << '\n';
        ret+=((end>>cnt)+1)*i;
    }
    return ret;
}
int main(){
    ll A, B; cin>>A>>B;
    // cout << "f("<<A<<")="<<f(A)<<'\n';
    // cout << "f("<<B<<")="<<f(B)<<'\n';
    cout << f(B)-f(A-1) << '\n';
}