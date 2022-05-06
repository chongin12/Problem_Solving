#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
int main(){
    ll N, K; cin>>N>>K;
    int cnt=0;
    ll p=1;
    while(N/p!=0) p*=10;
    N%=K;
    ll acc=1;
    while(cnt<=99999) {
        cnt++;
        if(acc*N%K==0){
            break;
        }
        acc=(acc*(p%K)+1)%K;
    }
    if(cnt>99999) cout << "-1\n";
    else cout << cnt << '\n';
}