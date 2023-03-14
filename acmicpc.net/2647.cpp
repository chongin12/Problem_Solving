#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
int dp[51][101][101]; // dp[i][j][k] : i층, j~k
struct node {
    int a,b,c;
    node(int a, int b, int c):a(a),b(b),c(c){}
};
node R[51][101][101];
void init(){
    for(int i=0;i<51;++i){
        for(int j=0; j<101; ++j){
            for(int k=0; k<101; ++k){
                dp[i][j][k]=INF;
            }
        }
    }
}
int main(){
    init();
    int n; cin>>n;
    string str; cin>>str;
    for(int i=1; i<n; ++i){
        if(str[i-1]!=str[i]) dp[1][i-1][i]=3;
    }
    for(int width=3; width<n-1; width+=2){
        for(int j=0; j+width<n; ++j){
            int k=j+width;
            for(int step=1; step<=(k-j+1)/2; ++step){
                for(int w=j+1; w<k-1; ++w){
                    // j ~ w 구간과 w+1 ~ k 구간으로 나눔.
                    // 두 그룹 중 하나는 목표 step, 다른 하나는 1부터 step까지 검색. 반대로도 해야함.
                    // R그룹도 갱신 필요.
                    
                }
            }
        }
    }
}