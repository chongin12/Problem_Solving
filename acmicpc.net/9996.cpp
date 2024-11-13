#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    string str; cin>>str;
    int idx=0;
    for(; idx<str.size(); ++idx){
        if(str[idx]=='*') break;
    }
    for(int i=0; i<N; ++i){
        string s; cin>>s;
        bool flag=true;
        if(s.size()<str.size()-1) flag=false;

        for(int j=0; j<idx; ++j){
            if(s[j]!=str[j]) flag=false;
        }
        for(int j=1; j<str.size()-idx; ++j){
            if(s[s.size()-j]!=str[str.size()-j]) flag=false;
        }
        if(flag) cout << "DA\n";
        else cout << "NE\n";
    }
}