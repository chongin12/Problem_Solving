#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
using pii = pair<int, int>;
vector<pii> v;
int dp[500][500]; // dp[x][y] = x~y 구간의 곱셈 연산 최솟값
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        int r, c; cin >> r >> c;
        v.push_back({r,c});
        if(i) dp[i-1][i] = v[i-1].first * v[i-1].second * v[i].second;
    }
    for(int i=0; i<500; ++i){
        for(int j=0; j<500; ++j){
            if(i!=j) dp[i][j] = INF;
            
        }
    }
    for(int i=2; i<=N; ++i){ // 합칠 총 구간 개수
        for(int j=0; j<=N-i; ++j){ // 합칠 구간 중 첫 구간의 첫 인덱스
            for(int k=1; k<=i; ++k){ // 첫 구간의 개수
                // (j, j+1, ... , j+k-1) | (j+k, j+k, ... , j+i-1)
                int area1 = dp[j][j+k-1];
                int area1_r = v[j].first;
                int area1_c = v[j+k-1].second;
                int area2 = dp[j+k][j+i-1];
                int area2_c = v[j+i-1].second;
                //cout << "area1, area1_r, area1_c, area2, area2_c : " << area1 << ", " << area1_r << ", " << area1_c << ", " << area2 << ", " << area2_c << '\n'; 
                dp[j][j+i-1] = min(dp[j][j+i-1], area1+area2+area1_r*area1_c*area2_c);
                //cout << "dp[" << j << "][" << j+i-1 << "] = " << dp[j][j+1-1] << '\n';
            }
        }
    }
    cout << dp[0][N-1] << '\n';
}