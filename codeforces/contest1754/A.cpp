#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        string str; cin>>str;
        int cnt=0;
        bool flag=true;
        while(!str.empty()){
            if(str.back()=='A'){
                cnt++;
            }
            else{
                if(cnt<=0){
                    flag=false;
                    break;
                }
                else{
                    cnt--;
                }
            }
            str.pop_back();
        }
        // if(cnt>0) flag=false;
        if(!flag) cout << "No\n";
        else cout << "Yes\n";
    }

}