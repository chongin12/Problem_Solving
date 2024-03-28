#include <bits/stdc++.h>
using namespace std;
int main(){
    int c=0;
    for(int i=0; i<4; ++i){
        int a; cin>>a; c+=a;
    }
    cout << c/60 << '\n' << c%60 << '\n';
}