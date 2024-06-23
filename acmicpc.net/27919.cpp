#include <bits/stdc++.h>
using namespace std;
int main(){
    string str; cin>>str;
    int UC=0, DP=0;
    for(auto it:str){
        if(it=='U' || it=='C') UC++;
        else DP++;
    }
    int u=0, d=0, p=0;
    if(UC>(DP+1)/2) u=1;
    if(DP>0) d=1, p=1;
    if(u+p+d==0) cout << "C\n";
    else {
        if(u) cout << "U";
        if(d) cout << "D";
        if(p) cout << "P";
        cout << '\n';
    }
}