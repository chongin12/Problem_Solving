#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[2][10001];
void init() {
    memset(dp, 0, sizeof dp);
}
ll parsing(string a){
    ll ret=0;
    for(int i=0; i<a.size(); ++i){
        if(a[i]=='.') continue;
        ret=ret*10+a[i]-'0';
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        ll N;
        string a; cin>>N>>a;
        if(N==0) return 0;
        init();
        ll M = parsing(a);

        for(ll i=1; i<=N; ++i){
            ll c; string temp; cin>>c>>temp;
            ll p=parsing(temp);
            for(ll j=0; j<p; ++j){
                dp[i%2][j]=dp[(i-1)%2][j];
            }
            for(ll j=p; j<=M; ++j){
                dp[i%2][j]=max({dp[(i-1)%2][j], dp[i%2][j-p]+c, dp[(i-1)%2][j-p]+c});
            }
        }
        cout << dp[N%2][M] << '\n';
    }
}