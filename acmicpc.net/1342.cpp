#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int cnt=0;
    sort(s.begin(), s.end());
    do {
        bool flag=true;
        for(int i=1; i<s.size(); ++i){
            if(s[i]==s[i-1]) {flag=false; break;}
        }
        if(flag) cnt++;
    } while(next_permutation(s.begin(), s.end()));
    cout << cnt << '\n';
}