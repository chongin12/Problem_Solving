#include <bits/stdc++.h>
using namespace std;
const int MOD = 16769023;
int main(){
    int n; cin>>n; n++;
    int res=1;
    for(int i=0; i<n/2; ++i){
        res*=2;
        res%=MOD;
    }
    cout << res << '\n';
}