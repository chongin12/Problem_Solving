#include <bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    for(int i=0; i<10; ++i){
        int a; cin>>a;
        t+=a;
    }
    if(t%4==0) cout << "N\n";
    if(t%4==1) cout << "E\n";
    if(t%4==2) cout << "S\n";
    if(t%4==3) cout << "W\n";
}