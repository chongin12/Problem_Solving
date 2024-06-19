#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, t; cin>>n>>m>>t;
    int res1=0, res2=11111;
    for(int i=0; i*n<=t; ++i){
        int j=(t-i*n)/m;
        int spare=t-i*n-j*m;
        if(res2>spare) res1=i+j,res2=spare;
        else if(res2==spare) res1=max(res1, i+j);
    }
    cout << res1 << " " << res2 << '\n';
}