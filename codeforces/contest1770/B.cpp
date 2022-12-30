#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        int a=1, b=n;
        for(int i=1; i<=n; ++i){
            if(i%2){
                cout << b-- << " ";
            }
            else{
                cout << a++ << " ";
            }
        }
        cout << '\n';
    }
}