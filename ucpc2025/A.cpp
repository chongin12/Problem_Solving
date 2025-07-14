#include <bits/stdc++.h>
using namespace std;
int main(){
    int r=300;
    for(int i=0; i<4; ++i){
        int a; cin>>a;
        r+=a;
    }
    if(r<=1800) cout << "Yes\n";
    else cout << "No\n";
}