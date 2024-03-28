#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
int dp[51][101][101]; // dp[i][j][k] : i층, j~k
struct node {
    int a,b,c; // {어느 위치에서 나눴는지(끝점연결이면 -1), 왼쪽 층 수, 오른쪽 층 수}
    node(int a, int b, int c):a(a),b(b),c(c){}
    node():node(0,0,0){}
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
vector<pair<int,int>> v;
void f(int step, int left, int right){
    if(step<=0 || left>=right) return;
    if(R[step][left][right].a==-1){
        v.push_back({left, right});
        f(step-1, left+1, right-1);
    }
    else{
        node k = R[step][left][right];
        f(k.b,left,k.a);
        f(k.c,k.a+1,right);
    }
}
int main(){
    init();
    int n; cin>>n;
    string str; cin>>str;
    for(int i=1; i<n; ++i){
        if(str[i-1]!=str[i]) {
            dp[1][i-1][i]=3;
            R[1][i-1][i]=node(-1,-1,-1);
        }
    }
    for(int width=3; width<=n-1; width+=2){
        for(int j=0; j+width<n; ++j){
            int k=j+width;
            for(int step=1; step<=(k-j+1)/2; ++step){
                for(int w=j+1; w<k-1; w+=2){
                    // j ~ w 구간과 w+1 ~ k 구간으로 나눔.
                    // j에서 k를 연결하는 경우
                    if(str[j]!=str[k]){
                        if(dp[step][j][k] > dp[step-1][j+1][k-1]+step*2+k-j){
                            dp[step][j][k] = dp[step-1][j+1][k-1]+step*2+k-j;
                            R[step][j][k] = node(-1,-1,-1);
                        }
                    }
                    // 두 그룹 중 하나는 목표 step, 다른 하나는 1부터 step까지 검색. 반대로도 해야함.
                    // R그룹도 갱신 필요.
                    int group1 = dp[step][j][w];
                    for(int group2Step=1; group2Step<=step; ++group2Step){
                        int group2 = dp[group2Step][w+1][k];
                        if(dp[step][j][k] > group1+group2){
                            dp[step][j][k] = group1+group2;
                            R[step][j][k] = node(w, step, group2Step);
                        }
                    }

                    group1 = dp[step][w+1][k];
                    for(int group2Step=1; group2Step<=step; ++group2Step){
                        int group2 = dp[group2Step][j][w];
                        if(dp[step][j][k] > group1+group2){
                            dp[step][j][k] = group1+group2;
                            R[step][j][k] = node(w, group2Step, step);
                        }
                    }
                    
                }
                // cout << "dp["<<step<<"]["<<j<<"]["<<k<<"]="<<dp[step][j][k]<<'\n';
            }
        }
    }
    int res = INF;
    node ridx;
    for(int i=1; i<=n/2; ++i){
        // cout << "dp["<<i<<"][0]["<<n-1<<"]="<<dp[i][0][n-1]<<'\n';
        if(res>dp[i][0][n-1]){
            res=dp[i][0][n-1];
            ridx=node(i,0,n-1);
        }
    }
    cout << res << '\n';
    f(ridx.a, ridx.b, ridx.c);
    for(auto it:v){
        cout << it.first+1 << " " << it.second+1 << '\n';
    }
}