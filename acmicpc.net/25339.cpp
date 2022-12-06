#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N,Q; cin>>N>>Q;
    int k=0;
    for(int i=1; i<=Q; ++i){
        int a, l, r; cin>>a>>l>>r;
        if(a==1) k=!k;
        else if((r-l+1)/2%2){
            k=!k;
        }
        cout << k << '\n';
    }
}