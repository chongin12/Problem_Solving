#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll p[500001];
ll N;
void init(){
    for(ll i=0; i<N; ++i) p[i]=i;
}
ll Find(ll a){
    if(p[a]==a) return a;
    return p[a]=Find(p[a]);
}
void Union(ll a){
    ll A=Find(a);
    ll B=Find((A-1+N)%N);
    p[A]=B;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll T; cin>>T;
    for(ll t=1; t<=T; ++t){
        cout << "Case #"<<t<<"\n";
        cin>>N;
        init();
        vector<ll> arr(N);
        ll tot=0;
        for(ll i=0; i<N; ++i){
            ll a; cin>>a; tot+=a;
            arr[i]=a;
            if(a>0) Union(i);
        }
        if(tot>=N || tot==0){
            cout << 1 << '\n';
            continue;
        }
        for(ll i=0; i<N; ++i){
            while(arr[i]>1){
                arr[Find(i)]+=1;
                arr[i]-=1;
                Union(i);
            }
        }
        
        // for(ll i=0; i<N; ++i){
        //     cout << "arr["<<i<<"]="<<arr[i]<<'\n';
        // }
        ll k=N;
        for(ll i=0; i<N/k; ++i){
            // cout << "i : " << i <<", k : " << k << '\n';
            bool pass=true;
            for(ll j=1; i+j*N/k<N; ++j){
                if(arr[i]!=arr[i+j*N/k]){
                    pass=false;
                    break;
                }
            }
            if(!pass){
                while(k>1){
                    k--;
                    if(N%k==0) break;
                }
                if(k==1) break;
                i=-1;
                continue;
            }
        }
        cout << N/k << '\n';
    }
}