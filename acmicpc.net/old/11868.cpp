#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int main(){
    int N; cin>>N;
    int res=0;
    for(int i=0; i<N; ++i){
        int a; cin>>a;
        res^=a;
    }
    if(res==0) cout << "cubelover\n";
    else cout << "koosaga\n";
}