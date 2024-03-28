#include <bits/stdc++.h>
using namespace std;
bool isVowel(char it){
    if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u') return true;
    return false;
}
int main(){
    while(1){
        string str; cin>>str;
        if(str=="end") break;
        bool flag=false;
        for(auto it:str){
            if(isVowel(it)){
                flag=true;
            }
        }
        if(flag){
            for(int i=2; i<str.size(); ++i){
                if(isVowel(str[i])==isVowel(str[i-1]) && isVowel(str[i-1])==isVowel(str[i-2])) flag=false;
            }
            for(int i=1; i<str.size(); ++i){
                if(str[i]==str[i-1] && str[i]!='e' && str[i]!='o') flag=false;
            }
        }
        cout << "<"<<str<<"> is ";
        if(!flag){
            cout << "not ";
        }
        cout << "acceptable.\n";

    }
}