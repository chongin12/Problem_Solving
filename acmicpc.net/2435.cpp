#include <bits/stdc++.h>
using namespace std;
int cnt[101];
int main(){
    int N,K; cin>>N>>K;
    for(int i=1; i<=N; ++i){
        int a; cin>>a;
        cnt[i]=cnt[i-1]+a;
    }
    int res=-987654321;
    for(int i=1; i<=N-K+1; ++i){
        res=max(res,cnt[i+K-1]-cnt[i-1]);
    }
    cout << res << '\n';
}