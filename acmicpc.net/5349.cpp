#include <bits/stdc++.h>
using namespace std;
int main(){
    set<string> s, res;
    while(1){
        string str; cin>>str;
        if(str=="000-00-0000") break;
        if(s.find(str) == s.end()) {
            s.insert(str);
        }
        else {
            res.insert(str);
        }
    }
    for(auto it:res){
        cout << it << '\n';
    }
}