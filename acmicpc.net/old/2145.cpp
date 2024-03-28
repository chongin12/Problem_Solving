#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n; cin>>n;
        if(n==0) break;
        while(n>=10){
            int r=0;
            while(n!=0){
                r+=n%10;
                n/=10;
            }
            n=r;
        }
        cout << n << '\n';
    }
}