#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    for(auto it:str){
        if(it>='a' && it<='z') cout << (char)(it-32);
        else cout << (char)(it+32);
    }
    cout << '\n';
}