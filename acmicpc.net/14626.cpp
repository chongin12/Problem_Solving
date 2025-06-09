#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    int cnt=0;
    int chk=0;
    for(int i=0; i<str.size()-1; ++i){
        if(str[i]=='*'){
            if(i%2) chk=3;
            else chk=1;
        }
        else if(i%2){
            cnt+=(str[i]-'0')*3;
        }
        else {
            cnt+=(str[i]-'0');
        }
    }
    cnt+=(str.back()-'0');
    int val=(10-cnt%10)%10;
    while(val%chk!=0) val+=10;
    cout << val/chk << '\n';
}