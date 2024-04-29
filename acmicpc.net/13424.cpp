#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
const int INF = 987654321;
void init(){
    for(int i=0; i<101; ++i){
        for(int j=0; j<101; ++j){
            dp[i][j]=INF;
            if(i==j) dp[i][j]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while(T--){
        init();
        int N, M; cin>>N>>M;
        for(int i=0; i<M; ++i){
            int a, b, c; cin>>a>>b>>c;
            dp[a][b]=min(dp[a][b], c);
            dp[b][a]=min(dp[b][a], c);
        }
        for(int k=1; k<=N; ++k){
            for(int i=1; i<=N; ++i){
                for(int j=1; j<=N; ++j){
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        int K; cin>>K;
        vector<int> v;
        for(int i=0; i<K; ++i){
            int a; cin>>a; v.push_back(a);
        }
        int res=INF+1, idx=-1;
        for(int i=1; i<=N; ++i){
            int cnt=0;
            for(auto it:v){
                cnt+=dp[it][i];
            }
            if(res>cnt) res=cnt, idx=i;
        }
        cout << idx << '\n';
    }
}