#include <bits/stdc++.h>
using namespace std;
set<string> s;
int isEnd(string str){
    for(int i=0; i<3; ++i){
        if(str[i*3]!='.' && str[i*3+0]==str[i*3+1] && str[i*3+1]==str[i*3+2]){
            return true;
        }
        if(str[i]!='.' && str[0+i]==str[3+i] && str[3+i]==str[6+i]){
            return true;
        }
    }
    if(str[4]=='.') return false;
    if(str[0]==str[4] && str[4]==str[8]) return true;
    if(str[2]==str[4] && str[4]==str[6]) return true;
    return false;
}
string temp;
void f(int phase, string ss){
    if(phase >= 9) {
        s.insert(ss);
        return;
    }
    if(isEnd(ss)) {
        s.insert(ss);
        return;
    }
    for(int i=0; i<9; ++i){
        if(ss[i]!='.') continue;
        temp = ss;
        if(phase%2==0) temp[i]='X';
        else temp[i]='O';
        f(phase+1, temp);
    }
}
void init() {
    string str = ".........";
    f(0, str);
    // for(auto it=s.begin(); it!=s.end(); ++it){
    //     cout << *it << '\n';
    // }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init();
    while(1){
        string str; cin>>str;
        if(str=="end") break;
        if(s.find(str) != s.end()) {
            cout << "valid\n";
        }
        else {
            cout << "invalid\n";
        }
    }

}