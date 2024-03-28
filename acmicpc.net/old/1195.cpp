#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1, s2; cin>>s1>>s2;
    int s1size=s1.size();
    int s2size=s2.size();
    int res=s1size+s2size;
    for(int shift=-s2size; shift<=s1size; ++shift){
        bool flag=true;
        int cnt=0;
        for(int i=0; i<s2size; ++i){
            int j=shift+i;
            if(j<0) continue;
            if(j>=s1size) continue;
            cnt++;
            if(s2[i]-'0'+s1[j]-'0'==4) {
                flag=false;
                break;
            }
        }
        if(flag) res=min(res,s1size+s2size-cnt);
    }
    cout << res << '\n';
}