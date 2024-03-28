#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    int cnt=0;
    string res="";
    for(int i=0; i<str.size(); ++i){
        if(str[i]=='X') cnt++;
        if(cnt==4) {
            res+="AAAA";
            cnt=0;
        }
        if(str[i]=='.'){
            if(cnt%2==1){
                cout << "-1\n";
                return 0;
            }
            else if(cnt==2) {
                res+="BB";
                cnt=0;
            }
            res+=".";
        }
    }
    if(cnt%2==1) {
        cout << "-1\n";
    }
    else{
        if(cnt==2) res+="BB";
        cout << res << '\n';
    }
}