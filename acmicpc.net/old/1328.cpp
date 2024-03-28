#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 1000000007;
ll fact[101];
ll combi[101][101];
ll dp[101][101]; // dp[i][j] : i개의 숫자가 있고, 증가수열 j개 만드는 경우의 수.
int main(){
    ll N, L, R; cin>>N>>L>>R;
    fact[0]=1;
    fact[1]=1;
    for(ll i=2; i<101; ++i){
        fact[i]=fact[i-1]*i%MOD;
    }
    combi[0][0]=1;
    combi[1][0]=1;
    combi[1][1]=1;
    for(ll i=2; i<101; ++i){
        combi[i][0]=1;
        for(ll j=1; j<i; ++j){
            combi[i][j]=combi[i-1][j-1]+combi[i-1][j];
            combi[i][j]%=MOD;
        }
        combi[i][i]=1;
    }
    
    dp[1][1]=1;
    for(int i=2; i<101; ++i){
        dp[i][1]=fact[i-1];
        for(int j=2; j<i; ++j){
            ll cnt=0;
            for(int k=2; k<=i; ++k){
                //가장 큰 수를 k번째에 놓았을 때
                ll temp=0;
                temp+=combi[i-1][k-1]*dp[k-1][j-1]%MOD;
                temp*=fact[i-k];
                temp%=MOD;
                cnt=(cnt+temp)%MOD;
            }
            dp[i][j]=cnt;
            // cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<'\n';
        }
        dp[i][i]=1;
    }
    ll res=0;
    for(int i=1; i<=N; ++i){
        // 가장 큰 수를 i번째에 놓았을 때
        if(i<L || N-i+1<R) continue;
        ll temp=combi[N-1][i-1];
        if(i!=1) temp=temp*dp[i-1][L-1]%MOD;
        if(i!=N) temp=temp*dp[N-i][R-1]%MOD;
        // cout << "combi : " << combi[N-1][i-1] << ", dp left : " << dp[i-1][L-1] << ", dp right : " << dp[N-i][R-1] << '\n'; 
        res=(res+temp)%MOD;
    }
    cout << res << '\n';
}