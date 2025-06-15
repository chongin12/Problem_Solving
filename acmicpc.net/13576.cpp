#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll Z[100001];
ll cnt[100001];
int main(){
    string str; cin>>str;
    ll N=str.size();
    Z[0]=N;
    ll L=0, R=0;
    for(ll i=1; i<N; ++i){
        // Z[i] 를 채우려 함
        if(R<i){ // 1. 힌트가 없을 때
            L=i, R=i-1;
            for(ll j=0; i+j<N; ++j){
                if(str[j]==str[i+j]){
                    R=i+j;
                }
                else{
                    break;
                }
            }
            Z[i]=R-L+1;
        }
        else {
            ll k=i-L; // L~R은 0~R-L 과 같고, 현재 L~R 사이에 i가, 0~R-L 사이에 k가 있다.
            if(Z[k]<R-i+1){ // 2-1. Z[k]가 현재의 L~R 범위를 벗어나지 않을 때
                Z[i]=Z[k];
            }
            else {  // 2-2. Z[k]가 현재의 L~R 범위를 벗어날 때
                L=i;
                for(ll j=R-i+1; i+j<N; ++j){
                    if(str[j]==str[i+j]){
                        R=i+j;
                    }
                    else {
                        break;
                    }
                }
                Z[i]=R-L+1;
            }
        }
    }
    ll sum=0;
    set<ll> res;
    for(ll i=0; i<N; ++i){
        // cout << "Z["<<i<<"]="<<Z[i]<<'\n';
        if(Z[i]) sum++;
        cnt[Z[i]]++;
        if(i+Z[i]==N){
            res.insert(Z[i]);
        }
    }
    cout << res.size() << '\n';
    for(ll i=1; i<100001; ++i){
        if(res.find(i)!=res.end()){
            cout << i << " " << sum << '\n';
        }
        sum-=cnt[i];
    }
}