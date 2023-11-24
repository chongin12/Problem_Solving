#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        string s1,s2;
        cin>>s1>>s2;
        if(cin.eof()) break;
        int idx=0;
        for(auto it:s2){
            if(idx>=s1.size()) break;
            if(it==s1[idx]) idx++;
        }
        if(idx==s1.size()) cout << "Yes\n";
        else cout << "No\n";
    }
}