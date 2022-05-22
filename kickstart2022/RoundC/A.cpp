#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    for(int i=1; i<=T; ++i){
        int N; cin>>N;
        string str; cin>>str;
        int k=0;
        for(int j=0; j<str.size(); ++j){
            if(str[j]>='0' && str[j]<='9') k=k|1;
            else if(str[j]>='a' && str[j]<='z') k=k|2;
            else if(str[j]>='A' && str[j]<='Z') k=k|4;
            else k=k|8;
        }
        if(!(k&1)) str+='0';
        if(!(k&2)) str+='a';
        if(!(k&4)) str+='A';
        if(!(k&8)) str+='#';
        for(int j=str.size(); j<7; ++j){
            str+='1';
        }
        cout << "Case #"<<i<<": "<<str << '\n';
    }
}