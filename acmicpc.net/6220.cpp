#include <bits/stdc++.h>
using namespace std;
int C, N;
int dp[1001][11];
vector<int> v;
int f(int amount, int phase){ // 현재 phase일 때, amount를 채우는 가장 작은 결과
    if(amount==0) return 0;
    int ret=987654321;
    if(phase==N) return ret;
    if(dp[amount][phase]!=0) return dp[amount][phase];
    for(int i=0; i*v[phase]<=amount; ++i){
        ret=min(ret,f(amount-i*v[phase], phase+1)+i);
    }
    return dp[amount][phase]=ret;
}
int main(){
    cin>>C>>N;
    for(int i=0; i<N; ++i){
        int a; cin>>a; v.push_back(a);
    }
    cout << f(C, 0) << '\n';
}