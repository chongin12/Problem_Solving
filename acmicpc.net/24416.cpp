#include <bits/stdc++.h>
using namespace std;
int dp1[50], dp2[50];
int main(){
    int N; cin>>N;
    dp1[1]=1;
    dp1[2]=1;
    dp2[1]=0;
    dp2[2]=0;
    for(int i=3; i<=N; ++i){
        dp1[i]=dp1[i-1]+dp1[i-2];
        dp2[i]=dp2[i-1]+1;
    }
    cout << dp1[N] << " " << dp2[N] << '\n';
}