#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int a; char ch; cin>>a>>ch;
        for(int i=1; i<=a; ++i){
            for(int j=0; j<i; ++j){
                cout << ch;
            }
            cout << '\n';
            ch++;
            if(ch>'Z') ch='A';
        }
        cout << '\n';
    }
}