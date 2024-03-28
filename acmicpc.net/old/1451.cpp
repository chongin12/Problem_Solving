#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll arr[51][51];
ll total=0;
ll res=0;
void f(ll a, ll b, ll c){
    res=max(res,a*b*c);
}
int main(){
    ll N,M; cin>>N>>M;
    vector<ll> r(N);
    vector<ll> c(M);
    for(int i=0; i<N; ++i){
        string str; cin>>str;
        for(int j=0; j<str.size(); ++j){
            arr[i][j]=str[j]-'0';
            r[i]+=arr[i][j];
            c[j]+=arr[i][j];
            total+=arr[i][j];
        }
    }
    if(N>=2 && M>=2){
        ll area1=0;
        for(int i=0; i<M-1; ++i){
            area1+=c[i];
            ll area2=0;
            for(int j=0; j<N-1; ++j){
                for(int k=i+1; k<M; ++k) area2+=arr[j][k];
                f(area1, area2, total-area1-area2);
            }
        }
        area1=0;
        for(int i=M-1; i>0; --i){
            area1+=c[i];
            ll area2=0;
            for(int j=0; j<N-1; ++j){
                for(int k=0; k<i; ++k) area2+=arr[j][k];
                f(area1, area2, total-area1-area2);
            }
        }
        area1=0;
        for(int i=0; i<N-1; ++i){
            area1+=r[i];
            ll area2=0;
            for(int j=0; j<M-1; ++j){
                for(int k=i+1; k<N; ++k) area2+=arr[k][j];
                f(area1, area2, total-area1-area2);
            }
        }
        area1=0;
        for(int i=N-1; i>0; --i){
            area1+=r[i];
            ll area2=0;
            for(int j=0; j<M-1; ++j){
                for(int k=0; k<i; ++k) area2+=arr[k][j];
                f(area1, area2, total-area1-area2);
            }
        }
    }
    if(M>=3){
        ll area1=0;
        for(int i=0; i<M-2; ++i){
            area1+=c[i];
            ll area2=0;
            for(int j=i+1; j<M-1; ++j){
                area2+=c[j];
                f(area1, area2, total-area1-area2);
            }
        }
    }
    if(N>=3){
        ll area1=0;
        for(int i=0; i<N-2; ++i){
            area1+=r[i];
            ll area2=0;
            for(int j=i+1; j<N-1; ++j){
                area2+=r[j];
                f(area1, area2, total-area1-area2);
            }
        }
    }
    cout << res << '\n';
}