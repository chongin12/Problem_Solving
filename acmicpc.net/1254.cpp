#include <bits/stdc++.h>
using namespace std;
int isPal(string s){
    string temp=s;
    reverse(temp.begin(), temp.end());
    return s==temp;
}
int main(){
    string str; cin>>str;
    for(int i=0; i<str.size(); ++i){
        string temp=str;
        for(int j=i-1; j>=0; --j){
            temp+=str[j];
        }
        if(isPal(temp)){
            cout << str.size()+i << '\n';
            return 0;
        }
    }
}