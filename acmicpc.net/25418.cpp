#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
const int INF = 987654321;
int A, K;
int f(int x){
    if(x==K) return 0;
    if(x>K) return INF;
    if(dp[x]) return dp[x];
    return dp[x]=min(f(x+1)+1, f(x*2)+1);
}
int main(){
    cin>>A>>K;
    for(int i=K-1; i>=A; --i){
        f(i);
    }
    cout << f(A) << '\n';
}