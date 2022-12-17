#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        string str; cin>>str;
        int k=str[0]-'0';
        for(int i=1; i<n; ++i){
            if(str[i]=='0') cout << "+";
            else if(str[i]=='1'){
                if(k==0) {
                    cout << "+";
                    k+=1;
                }
                else{
                    cout << "-";
                    k-=1;
                }
            }
        }
        cout << '\n';
    }
}