#include <bits/stdc++.h>
using namespace std;
const int MN = 1000001;
int dp[MN];
int main(){
    int N; cin>>N;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=4;
    for(int i=5; i<=N; ++i){
        dp[i]=dp[i-3]*3%10007;
    }
    cout << dp[N] << '\n';
}

/*
1로 분해하면 의미 없음. 이런 경우는 절대 없음.
2 -> 2
3 -> 3
4 -> 4
5 -> 6
6 -> 9
7 -> 12
8 -> 18
9 -> 27
10 -> 36
11 -> 54
12 -> 81
*/