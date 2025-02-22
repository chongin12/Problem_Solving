#include <bits/stdc++.h>
using namespace std;
int main(){
    int H, W; cin>>H>>W;
    for(int i=0; i<H; ++i){
        string s; cin>>s;
        int prev=987;
        for(int j=0; j<W; ++j){
            if(s[j]=='c') prev=j;
            cout << max(-1, j-prev) << ' ';
        }
        cout << '\n';
    }
}