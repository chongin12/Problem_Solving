#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b; cin>>a>>b;
    int c=0, d=0, e=1;
    string str="";
    for(int i=0; i<8; ++i){
        str+=a[i];
        str+=b[i];
    }
    while(str.size()>=3){
        string nxt="";
        for(int i=0; i<str.size()-1; ++i){
            nxt+=(str[i]-'0'+str[i+1]-'0')%10+'0';
        }
        str=nxt;
    }
    cout << str << '\n';
}