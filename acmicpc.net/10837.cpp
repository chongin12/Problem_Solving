#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int K, C; cin>>K>>C;
    for(int i=0; i<C; ++i){
        int a,b; cin>>a>>b;
        
        int ret=0;
        if(a==b || a==b+1) ret=1;
        else if(a>b && a>=b+2 && a<=b+K-a+2) ret=1;
        else if(a<b && b>=a+1 && b<=a+K-b) ret=1;
        else if(a>b && a>=b+1 && a<=b+K-a+1) ret=1;
        else if(a<b && b>=a+1 && b<=a+K-b+1) ret=1;
        if(ret) cout << "1\n";
        else cout << "0\n";
    }
}