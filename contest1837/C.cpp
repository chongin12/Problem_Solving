#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<char,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        string str; cin>>str;
        int prev=-1;
        int previdx=-1;
        for(int i=0; i<str.size(); ++i){
            if(str[i]!='?') {
                if(prev==-1){
                    for(int j=0; j<i; ++j){
                        str[j]=str[i];
                    }
                }
                else if(prev==str[i]){
                    for(int j=previdx+1; j<i; ++j){
                        str[j]=str[i];
                    }
                }
                else {
                    for(int j=previdx+1; j<i; ++j){
                        str[j]=prev;
                    }
                }
                prev=str[i];
                previdx=i;
            }
        }
        if(prev==-1){
            prev='0';
        }
        for(int j=previdx+1; j<str.size(); ++j){
            str[j]=prev;
        }
        cout << str << '\n';
    }
}