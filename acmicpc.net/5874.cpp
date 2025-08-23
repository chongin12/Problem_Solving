#include <bits/stdc++.h>
using namespace std;
int main(){
    int res=0;
    int cnt=0;
    string str; cin>>str;
    for(int i=1; i<str.size(); ++i){
        if(str[i]==str[i-1]){
            if(str[i]=='(') cnt++;
            else res+=cnt;
        }
    }
    cout << res << '\n';
}
