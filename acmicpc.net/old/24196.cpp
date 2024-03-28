#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    string ans = "";
    int idx=0;
    while(idx<str.size()-1){
        ans+=str[idx];
        idx+=str[idx]-'A'+1;
    }
    ans+=str[idx];
    cout << ans << '\n';
}