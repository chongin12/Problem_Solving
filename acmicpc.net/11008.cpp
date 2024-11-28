#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    while(n--){
        string s1, s2; cin>>s1>>s2;
        int r=0;
        for(int i=0; i<s1.size(); ++i){
            r++;
            bool flag=true;
            for(int j=0; j<s2.size(); ++j){
                if(i+j>=s1.size() || s1[i+j]!=s2[j]) flag=false;
            }
            if(flag){
                i+=s2.size()-1;
            }
        }
        cout << r << '\n';
    }
}