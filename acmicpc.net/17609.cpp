#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        string s; cin>>s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        int l=-1, r=-1;
        int res=-1;
        for(int i=0; i<s.size(); ++i){
            if(s[i]!=rs[i]){
                l=i;
                break;
            }
            if(i==s.size()-1) res=0;
        }
        if(res!=-1) {
            cout << res << '\n';
            continue;
        }
        for(int i=s.size()-1; i>=0; --i){
            if(s[i]!=rs[i]){
                r=i;
                break;
            }
        }
        int flag=true;
        for(int i=l; i<r; ++i){
            if(s[i]!=rs[i+1]){
                flag=false;
                break;
            }
        }
        if(!flag){
            flag=true;
            for(int i=l; i<r; ++i){
                if(s[i+1]!=rs[i]){
                    flag=false;
                    break;
                }
            }
        }
        if(!flag) res=2;
        else res=1;
        cout << res << '\n';
    }
}
