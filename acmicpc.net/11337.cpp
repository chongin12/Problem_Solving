#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    cout << fixed;
    cout.precision(3);
    while(T--){
        double r, b; cin>>r>>b;
        if(sqrt(r*r*2)<=b){
            cout << r*r*2 << '\n';
        }
        else {
            cout << sqrt(r*r*4-b*b)*b << '\n';
        }
    }
}