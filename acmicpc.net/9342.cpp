#include <bits/stdc++.h>
using namespace std;
bool f1(string str){
    int idx=0;
    if(str[idx]=='A' || str[idx]=='B' || str[idx]=='C' || str[idx]=='D' || str[idx]=='E' || str[idx]=='F'){
        idx++;
        if(idx>=str.size() || str[idx]!='A') return false;
        while(idx<str.size() && str[idx]=='A') idx++;
        if(idx>=str.size() || str[idx]!='F') return false;
        while(idx<str.size() && str[idx]=='F') idx++;
        if(idx>=str.size() || str[idx]!='C') return false;
        while(idx<str.size() && str[idx]=='C') idx++;
        if(idx>=str.size()) return true;
        else if(idx==str.size()-1 && (str[idx]=='A' || str[idx]=='B' || str[idx]=='C' || str[idx]=='D' || str[idx]=='E' || str[idx]=='F')) return true;
        else return false;
    }
    return false;
}
bool f2(string str){
    int idx=0;
    if(idx>=str.size() || str[idx]!='A') return false;
    while(idx<str.size() && str[idx]=='A') idx++;
    if(idx>=str.size() || str[idx]!='F') return false;
    while(idx<str.size() && str[idx]=='F') idx++;
    if(idx>=str.size() || str[idx]!='C') return false;
    while(idx<str.size() && str[idx]=='C') idx++;
    if(idx>=str.size()) return true;
    else if(idx==str.size()-1 && (str[idx]=='A' || str[idx]=='B' || str[idx]=='C' || str[idx]=='D' || str[idx]=='E' || str[idx]=='F')) return true;
    else return false;
}
int main(){
    int T; cin>>T;
    while(T--){
        string str; cin>>str;
        if(f1(str)) cout << "Infected!\n";
        else if(f2(str)) cout << "Infected!\n";
        else cout << "Good\n";
    }
}