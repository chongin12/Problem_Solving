#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    for(int i=0; i<T; ++i){
        int a,b,c; cin>>a>>b>>c;
        cout << min({a,b,c}) << '\n';
    }
}