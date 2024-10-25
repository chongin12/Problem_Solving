#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int a;
    for(int i=2; i<=n-1; ++i){
        cout << "? " << i << '\n';
        cout << flush;
        cin>>a;
        if(a==1){
            cout << "! " <<i-1 << '\n';
            cout << flush;
            return 0;
        }
    }
    cout << "! " << n-1 << '\n';
    cout << flush;
}