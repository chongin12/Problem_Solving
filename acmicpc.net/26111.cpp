#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    // ((()()())())
    string str; cin>>str;
    ll res=0;
    ll cnt=0;
    for(int i=0; i<str.size(); ++i){
        if(str[i]=='(') cnt++;
        else {
            if(str[i-1]=='(') res+=cnt-1;
            cnt--;
        }
    }
    cout << res << '\n';
}