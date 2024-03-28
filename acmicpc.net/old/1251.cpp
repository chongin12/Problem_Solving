#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    string res="";
    for(int i=1; i<str.size()-1; ++i){
        for(int j=i+1; j<str.size(); ++j){
            //str[0]~, str[i]~, str[j]~
            string temp="";
            for(int k=i-1; k>=0; --k) {
                temp+=str[k];
            }
            for(int k=j-1; k>=i; --k){
                temp+=str[k];
            }
            for(int k=str.size()-1; k>=j; --k){
                temp+=str[k];
            }
            if(res=="") res=temp;
            else res=min(res,temp);
        }
    }
    cout << res << '\n';
}