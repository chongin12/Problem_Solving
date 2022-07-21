#include <bits/stdc++.h>
using namespace std;
int XOR(int x){
    int ret=0;
    if(x%2==0){
        ret=x;
    }
    if(x%4==1 || x%4==2){
        ret|=1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int S,F; cin>>S>>F;
        int res=XOR(F)^XOR(S-1);
        cout << res << '\n';
    }
}