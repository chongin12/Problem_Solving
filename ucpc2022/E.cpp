#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ll mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll N; cin>>N;
    vector<pair<ll,ll> > v;
    if(N==0) {
        cout << "0\n";
        return 0;
    }
    for(int i=0; i<N; ++i){
        string a,b; ll c; cin>>a>>b>>c;
        ll acc=0;
        ll k=0;
        vector<ll> p;
        for(int j=0; j<a.size(); ++j){
            if(a[j]=='/'){
                p.push_back(k);
                k=0;
            }
            else{
                k=k*10+a[j]-'0';
            }
        }
        acc+=k-1;
        ll shift=6; // 2019년 6월 6일
        for(int j=1; j<=5; ++j) shift+=mon[j];
        if(p[0]==2019){
            for(int j=1; j<p[1]; ++j){
                acc+=mon[j];
            }
        }
        else if(p[0]==2020){
            for(int j=1; j<=12; ++j){
                acc+=mon[j];
            }
            mon[2]=29;
            for(int j=1; j<p[1]; ++j){
                acc+=mon[j];
            }
            mon[2]=28;
        }
        else if(p[0]==2021){
            for(int j=1; j<=12; ++j){
                acc+=mon[j];
            }
            mon[2]=29;
            for(int j=1; j<=12; ++j){
                acc+=mon[j];
            }
            mon[2]=28;
            for(int j=1; j<p[1]; ++j){
                acc+=mon[j];
            }
        }
        else{
            for(int j=1; j<=12; ++j){
                acc+=mon[j];
            }
            mon[2]=29;
            for(int j=1; j<=12; ++j){
                acc+=mon[j];
            }
            mon[2]=28;
            for(int j=1; j<=12; ++j){
                acc+=mon[j];
            }
            for(int j=1; j<p[1]; ++j){
                acc+=mon[j];
            }
        }
        acc-=shift;
        acc*=24*60*60;//일->초로 바꿈
        p.clear();
        k=0;
        for(int j=0; j<b.size(); ++j){
            if(b[j]==':'){
                p.push_back(k);
                k=0;
            }
            else{
                k=k*10+b[j]-'0';
            }
        }
        acc+=k;
        acc+=p[0]*60*60;
        acc+=p[1]*60;
        v.push_back({acc,c});
    }
    for(int i=v.size()-1; i>=0; --i){
        v[i].first-=v[0].first;
    }
    long double bunmo=0, bunza=0;
    vector<long double> P,L;
    for(int i=0; i<v.size(); ++i){
        P.push_back(max(pow(0.5,(v.back().first-v[i].first)/(365.0*24*60*60)), pow(0.9,N-(i+1))));
        L.push_back(v[i].second);
    }
    for(int i=0; i<P.size(); ++i){
        bunza+=P[i]*L[i];
        bunmo+=P[i];
    }
    cout << round(bunza/bunmo) << '\n';
}