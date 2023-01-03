#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        string str; cin>>str;
        int flag=0;
        bool res=false;
        for(int i=0; i<n; ++i){
            if(flag==0){
                if(str[i]=='R') flag=1;
            }
            else{
                if(str[i]=='L') flag=2;
            }
        }
        if(flag==2){
            cout << "0\n";
            res=true;
        }
        else{
            for(int i=1; i<n; ++i){
                if(str[i-1]=='L' && str[i]=='R'){
                    cout << i << '\n';
                    res=true;
                    break;
                }
            }
        }
        if(!res){
            cout << "-1\n";
        }
    }
}