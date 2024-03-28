#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; getline(cin, str);
    string str2; getline(cin, str2);
    int res=0;
    for(int i=0; i<str.size(); ++i){
        for(int j=0; j<str2.size(); ++j){
            if(str[i+j]!=str2[j]) break;
            if(j==str2.size()-1){
                res++;
                i+=str2.size()-1;
            }
        }
    }
    cout << res << '\n';
}