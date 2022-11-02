#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        if(n%2){
            for(int i=(2+n)/2; i>=2; --i){
                cout << i << " " << i+n/2 << " ";
            }
            cout << "1\n";
        }
        else{
            for(int i=n/2; i>=1; --i){
                cout << i << " " << i+n/2 << " ";
            }
            cout << '\n';
        }
    }
}