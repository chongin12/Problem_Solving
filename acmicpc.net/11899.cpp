#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    vector<char> stk;
    for(auto it:str){
        if(!stk.empty() && stk.back()=='(' && it==')'){
            stk.pop_back();
        }
        else{
            stk.push_back(it);
        }
    }
    cout << stk.size() << '\n';
}