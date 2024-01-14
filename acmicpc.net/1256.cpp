#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAX = 1000000000;
ll dp[201][101]; // dp[i][j] : 문자 총 i개, 그 중 a가 j개일 때 총 개수
int main(){
    ll N, M, K; cin>>N>>M>>K;
    for(ll i=1; i<=M; ++i){
        dp[i][0]=1;
    }
    for(ll i=1; i<=N; ++i){
        dp[i][i]=1;
    }
    for(ll i=2; i<=N+M; ++i){ // 총 i개
        for(ll a=1; a<=N; ++a){
            // a가 a개일 때
            ll z=i-a; // z는 i-a개.
            if(z>M || z<=0) continue;
            dp[i][a]+=dp[i-1][a];
            dp[i][a]+=dp[i-1][a-1];
            if(dp[i][a]>MAX) dp[i][a]=MAX+10;
            // cout << "dp["<<i<<"]["<<a<<"]="<<dp[i][a] << '\n';
        }
    }
    if(K>dp[N+M][N]) {
        cout << "-1\n";
        return 0;
    }
    ll a=N, z=M;
    string res="";
    ll acc=0;
    while(a>0 || z>0){
        if(a==0){
            res+='z';
            z-=1;
        }
        else if(z==0){
            res+='a';
            a-=1;
        }
        else{
            // a 를 넣을지, z를 넣을지 고민
            
            //a를 넣어도 목표치에 안되면 z를 넣어야 함.
            if(acc+dp[a+z-1][a-1]<K){
                acc+=dp[a+z-1][a-1];
                z-=1;
                res+='z';
            }
            else{
                a-=1;
                res+='a';
            }
        }
    }
    cout << res << '\n';
}