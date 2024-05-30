#include <bits/stdc++.h>
using namespace std;
int N;
string str="";
bool isEnd = false;
bool check() {
    int lastIdx = str.size()-1;
    if(str.size()==1) return false;
    if(str.size()==2){
        return str[lastIdx]==str[lastIdx-1];
    }
    for(int i=1;;++i){
        int preLastIdx = lastIdx-i;
        if(preLastIdx < 0) {
            break;
        }
        bool flag=true;
        for(int j=0; j<i; ++j){
            if(str[lastIdx-j]!=str[preLastIdx-j]){
                flag=false;
                break;
            }
        }
        if(flag) return true;
    }
    return false;
}
void f(int phase){
    if(phase==N+1){
        cout << str << '\n';
        isEnd = true;
        return;
    }
    for(int i=1; i<=3; ++i){
        str+='0'+i;
        if(check()) {
            str.pop_back();
            continue;
        }
        f(phase+1);
        if(isEnd) return;
        str.pop_back();
    }
}
int main(){
    cin>>N;
    f(1);
}