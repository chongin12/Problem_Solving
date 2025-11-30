#include <bits/stdc++.h>
using namespace std;
int combi(int n, int m){
    int ret=1;
    for(int i=0; i<m; ++i){
        ret*=(n-i);
    }
    for(int i=0; i<m; ++i){
        ret/=(m-i);
    }
    return ret;
}
int main(){
    int N, M, K; cin>>N>>M>>K;
    cout.precision(9);
    cout << fixed;
    int cnt=0;
    for(int i=K; i<=M; ++i){
        cnt+=combi(M,i)*combi(N-M,M-i);
    }
    cout << (double)cnt/combi(N,M) << '\n';
}