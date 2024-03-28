#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
const int MN=2000001;
ll A[MN*2];
void manachers(string s, ll N){
    ll r=0, p=0;
    for(ll i=0; i<N; ++i){
        if(i<=r){
            A[i]=min(A[2*p-i], r-i);
        }
        else{
            A[i]=0;
        }

        while(i-A[i]-1>=0 && i+A[i]+1<N && s[i-A[i]-1]==s[i+A[i]+1]) A[i]++;

        if(r<i+A[i]){
            r=i+A[i];
            p=i;
        }
    }
}
int main(){
    string tmp; cin>>tmp;
    string str="";
    for(int i=0; i<tmp.size(); ++i){
        str+='#';
        str+=tmp[i];
    }
    str+='#';

    manachers(str, str.size());

    long long int res=0;
    for(int i=0; i<str.size(); ++i){
        res+=(A[i]+1)/2;
    }
    cout << res << '\n';
}