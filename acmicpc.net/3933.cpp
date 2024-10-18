#include <bits/stdc++.h>
using namespace std;
int dp[32769][200][5]; // dp[i][j][k] : i를 구성할 때 가장 큰 원소를 j*j로 써서 구성한 k자리 수 개수
void init(){
    dp[1][1][1]=1;
    for(int i=2; i<32769; ++i){
        for(int j=1; j*j<=i; ++j){
            if(j*j==i) { dp[i][j][1]=1; break; }
            for(int k=2; k<=4; ++k){
                for(int w=1; w<=j; ++w){
                    dp[i][j][k]+=dp[i-j*j][w][k-1];
                }
            }
        }
    }
}
int main(){
    init();
    while(1){
        int a; cin>>a;
        if(a==0) return 0;
        int res=0;
        for(int i=1; i<200; ++i){
            res+=dp[a][i][1]+dp[a][i][2]+dp[a][i][3]+dp[a][i][4];
        }
        cout << res << '\n';
    }
}