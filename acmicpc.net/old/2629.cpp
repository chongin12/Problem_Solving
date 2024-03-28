#include <iostream>
#define R 50000
using namespace std;
int dp[30][100001]; 
// dp[i][j] : i번째 추가 있을 때, 구슬의 무게가 j라면 확인할 수 있는지
// 이전꺼에서 i번째 추를 빼거나 더하면서 dp추가
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        dp[i][a+R] = 1;
       // cout << "dp[" << i << "][" << a+R << "]=1\n";
        if(i) {
            for(int j=0; j<=100000; ++j){
                if(dp[i-1][j]){
                    dp[i][j]=1;
                    dp[i][j-a] = 1;
                    dp[i][j+a] = 1;
                    //cout << "i-1 : " << i-1 << ", j : " << j << ", a : " << a << '\n';
                }
            }
        }
    }
    int M; cin >> M;
    for(int i=0; i<M; ++i){
        int a; cin >> a;
        if(dp[N-1][a+R] || dp[N-1][R-a]) cout << 'Y' << '\n';
        else cout << 'N' << '\n';
    }
}