#include <iostream>
using namespace std;
int dp[2001][2001]; // dp[i][j] : i ~ j가 펠린드롬인지 여부
int arr[2001];
int N;
void f() {
    for(int i=1; i<=N; ++i){ // length
        for(int j=1; j<=N-i+1; ++j){ // start point
            if(i==1) dp[j][j] = 1;
            else if(i==2 && arr[j]==arr[j+1]) dp[j][j+1] = 1;
            else {
                //length>=3
                if(dp[j+1][j+i-2] && arr[j] == arr[j+i-1]) dp[j][j+i-1]=1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
    }
    f();
    int M; cin >> M;
    int S, E;
    while(M--){
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }
}
