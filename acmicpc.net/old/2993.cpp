#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    string res=str;
    for(int i=0; i<str.size()-2; ++i){
        for(int j=i+1; j<str.size()-1; ++j){
            // 0~i, i+1~j, j+1~str.size()-1
            string temp="";
            for(int k=i; k>=0; --k){
                temp+=str[k];
            }
            for(int k=j; k>=i+1; --k){
                temp+=str[k];
            }
            for(int k=str.size()-1; k>=j+1; --k){
                temp+=str[k];
            }
            if(res>temp) res=temp;
        }
    }
    cout << res << '\n';
}