#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        string str; cin>>str;
        vector<int> v(26);
        reverse(str.begin(), str.end());
        bool flag=true;
        while(!str.empty()) {
            int lastChIdx = str.back()-'A'; str.pop_back();
            v[lastChIdx]++;
            if(v[lastChIdx]==3){
                if(str.back()-'A'==lastChIdx){
                    str.pop_back();
                    v[lastChIdx]=0;
                }
                else{
                    flag=false;
                    break;
                }
            }
        }
        if(flag) cout << "OK\n";
        else cout << "FAKE\n";
    }
}