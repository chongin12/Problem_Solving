#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int res=987654321;
    for(int i=0; i<n; ++i){
        int a,b; cin>>a>>b;
        if(a<=b) res=min(res,b);
    }
    if(res==987654321) res=-1;
    cout << res << '\n';
}