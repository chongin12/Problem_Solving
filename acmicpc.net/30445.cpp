#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int a=0, b=0;
    for(auto it:s){
        if(it=='S' || it=='A' || it=='D') {
            b+=1;
        }
        if(it=='H' || it=='A' || it=='P' || it=='Y') {
            a+=1;
        }
    }
    cout << fixed;
    cout.precision(2);
    if(a==0 && b==0) cout << "50.00\n";
    else {
        double res = (double)a/(a+b)*100 + 1e-9;
        cout << res << '\n';
    }
}