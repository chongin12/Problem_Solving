#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int k=10;
    while(n>=k){
        if(n%k>=k/2){
            n=n-n%k+k;
        }
        else {
            n=n-n%k;
        }
        k*=10;
    }
    cout << n << '\n';
}
