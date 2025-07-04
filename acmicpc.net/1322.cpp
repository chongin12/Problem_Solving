#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll X, K; cin>>X>>K;
    string s="";
    while(K){
        if(K%2) s="1"+s;
        else s="0"+s;
        K/=2;
    }
    string res="";
    while(X){
        if(X%2) res+="0";
        else {
            if(s.empty()) break;
            res+=s.back();
            s.pop_back();
        }
        X/=2;
    }
    while(!s.empty()){
        res+=s.back();
        s.pop_back();
    }
    ll r=0;
    ll t=1;
    for(auto it:res){
        if(it=='1'){
            r+=t;
        }
        t*=2;
    }
    cout <<r << '\n';
}