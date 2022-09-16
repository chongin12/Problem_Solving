#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int cnt=0;
    for(int i=1; i<n-2; ++i){
        cnt+=i*(n-2-i);
    }
    cout << cnt*n/4 << '\n';
}