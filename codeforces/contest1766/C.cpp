#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int N; cin>>N;
        string s[2]; cin>>s[0]>>s[1];
        bool pass=true;
        int pos=0;
        for(int i=0; i<N; ++i){
            if(s[pos][i]=='W'){
                pass=false;
                break;
            }
            else if(s[!pos][i]=='B'){
                pos=!pos;
            }
        }
        if(!pass){
            pass=true;
            pos=1;
            for(int i=0; i<N; ++i){
                if(s[pos][i]=='W'){
                    pass=false;
                    break;
                }
                else if(s[!pos][i]=='B'){
                    pos=!pos;
                }
            }
        }
        if(pass) cout << "YES\n";
        else cout << "NO\n";
    }
}