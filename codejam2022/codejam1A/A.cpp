#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        int visited[101]={};
        string str; cin>>str;
        string res="";
        for(int i=0; i<str.size(); ++i){
            if(i&&str[i-1]<str[i]) {
                int k=i-1;
                while(k>=0 && !visited[k] && str[k]==str[i-1]) k--;
                ++k;
                while(k<=i-1){
                    visited[k++]=1;
                }
            }
        }
        for(int i=0; i<str.size(); ++i){
            res+=str[i];
            if(visited[i]) res+=str[i];
        }
        cout << "Case #"<<t<<": "<<res<<'\n';
    }
}