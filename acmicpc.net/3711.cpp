#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int G; cin>>G;
        vector<int> v;
        for(int a,i=0; i<G; ++i){
            cin>>a; v.push_back(a);
        }
        int m;
        for(m=G; ; ++m){
            bool flag=false;
            vector<int> chk(m+1);
            for(auto it:v){
                if(chk[it%m]) {
                    flag=true;
                    break;
                }
                else{
                    chk[it%m]=1;
                }
            }
            if(!flag) break;
        }
        cout << m << '\n';
    }
}