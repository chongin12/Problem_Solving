#include <bits/stdc++.h>
using namespace std;
string str;
int res=0;
int sz;
void f(int idx){
    if(idx>=sz){
        res=1;
        return;
    }
    if(str[idx]=='0'){
        if(str[idx+1]=='1'){
            f(idx+2);
        }
    }
    else{
        if(str[idx+1]=='0' && str[idx+2]=='0'){
            for(idx=idx+3; idx<sz; ++idx){
                if(str[idx]=='1') break;
            }
            if(idx>=sz) return;
            idx++;
            for(;idx<=sz; ++idx){
                f(idx);
                if(str[idx]!='1') break;
            }
        }
    }
}
int main(){
    res=0;
    cin>>str;
    sz=str.size();
    str+="####";
    f(0);
    cout << (res==1?"SUBMARINE":"NOISE") << "\n";
}