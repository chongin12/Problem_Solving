#include <bits/stdc++.h>
using namespace std;
const int MOD = 123456789;
int isErased[40001];
int dp[40001][2]; // dp[i] = i원을 만드는 경우의 수 (토글링)
vector<int> primes;
int main(){
    int N; cin>>N;
    for(int i=2; i*i<=40000; ++i){
        if(isErased[i]) continue;
        for(int j=i*i; j<=40000; j+=i){
            isErased[j]=true;
        }
    }
    for(int i=2; i<=40000; ++i){
        if(!isErased[i]) primes.push_back(i);
    }

    for(int i=0; i<primes.size(); ++i){
        int prime = primes[i];
        for(int j=2; j<prime; ++j){
            dp[j][i%2]=dp[j][(i+1)%2];
        }
        dp[prime][i%2]=(dp[prime][(i+1)%2]+1)%MOD;
        for(int j=prime+1; j<=N; ++j){
            dp[j][i%2]=(dp[j][(i+1)%2]+dp[j-prime][i%2])%MOD;
        }
    }
    cout << dp[N][(primes.size()+1)%2] << '\n';
    
}
/*
2원까지 있을 때
dp[2]=1
dp[3]=0
dp[4]=1
dp[5]=0
dp[6]=1
dp[7]=0
dp[8]=1
3원까지 있을 때
dp[2]=1
dp[3]=1
dp[4]=1
dp[5]=1
dp[6]=2
dp[7]=1
dp[8]=2
5원까지 있을 때
dp[2]=1
dp[3]=1
dp[4]=1
dp[5]=2=dp[5][i-1]+1
dp[6]=2=dp[6][i-1]+dp[1][i]
dp[7]=2=dp[7][i-1]+dp[2][i]
dp[8]=3=dp[8][i-1]+dp[3][i]
*/