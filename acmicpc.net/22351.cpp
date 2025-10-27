#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    for(int i=1; i<1500; ++i){
        if(str.size()==i){
            cout << str << " " << str << '\n';
            break;
        }
        string temp1="";
        for(int j=0; j<i; ++j) temp1+=str[j];
        string temp="";
        int k=stoi(temp1);
        while(temp.size()<str.size()){
            temp+=to_string(k);
            k++;
        }
        if(str==temp){
            cout << stoi(temp1) << " " << k-1 << '\n';
            break;
        }
    }
}